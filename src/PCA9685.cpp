#include "PCA9685.h"
#include "RobotLeg.h"
#include <iostream>
#include <vector>
#include <cstdint>
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

class PCA9685 {
private:
    int i2c_fd;
    const char* I2C_DEV = "/dev/i2c-1";
    const int PRESCALER_50HZ = 121;
    std::vector<RobotLeg> legs;
    
    void writeRegister(uint8_t reg, uint8_t value) {
        if (i2c_smbus_write_byte_data(i2c_fd, reg, value) < 0) {
            std::cerr << "Failed to write to I2C device" << std::endl;
        }
    }

public:
    PCA9685(uint8_t address) {
        // Open I2C bus
        if ((i2c_fd = open(I2C_DEV, O_RDWR)) < 0) {
            std::cerr << "Failed to open I2C bus" << std::endl;
            return;
        }

        // Set I2C address
        if (ioctl(i2c_fd, I2C_SLAVE, address) < 0) {
            std::cerr << "Failed to set I2C address" << std::endl;
            return;
        }

        // Initialize PWM controller
        writeRegister(0x00, 0x10);    // Enter sleep mode
        writeRegister(0xFE, PRESCALER_50HZ); // Set prescaler
        writeRegister(0x00, 0x80);    // Wake up
        usleep(5000);                 // Wait for oscillator
    }

    ~PCA9685() {
        if (i2c_fd >= 0) close(i2c_fd);
    }

    void setServoPulse(uint8_t channel, float pulse_ms) {
        // Convert pulse time to 12-bit value
        float pulse = pulse_ms * 4096 / 20; // 20ms = 50Hz period
        uint16_t off_value = static_cast<uint16_t>(pulse);
    
        // Calculate register offsets (4 bytes per channel)
        uint8_t off_low = 0x08 + (4 * channel % 16);
        uint8_t off_high = 0x09 + (4 * channel % 16);
    
        // Write PWM values
        writeRegister(off_low, off_value & 0xFF);
        writeRegister(off_high, (off_value >> 8) & 0x0F);
    }

    void addLeg(int ch0, int ch1, int ch2) {
        legs.push_back(RobotLeg(ch0, ch1, ch2));
    }
};