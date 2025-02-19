#pragma once

#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <thread>

#include <sys/ioctl.h>
#include <fcntl.h>

extern "C" {
    #include <linux/i2c-dev.h>
    #include <i2c/smbus.h>
}

class PCA9685 {
private:
    int i2c_fd;
    static constexpr const char* I2C_DEV = "/dev/i2c-1";
    static constexpr uint8_t PRESCALER_50HZ = 121;
    std::vector<std::array<short, 3>> legs;
    uint8_t address;

    void writeRegister(uint8_t reg, uint8_t value);
    void setServoPulse(uint8_t channel, float pulse_ms);

public:
    explicit PCA9685(uint8_t newAddress);
    ~PCA9685();

    void setChannelPulse(short leg, short channel, float pulse_ms);
    void addLeg(std::array<short, 3>& channels);
    std::string getAddress();
    short legsAmount() const;
};