#ifndef PCA9685_H
#define PCA9685_H

#include "RobotLeg.h"
#include <vector>
#include <cstdint>
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

class PCA9685 {
private:
    int i2c_fd;
    static constexpr const char* I2C_DEV = "/dev/i2c-1";
    static constexpr int PRESCALER_50HZ = 121;
    std::vector<RobotLeg> legs;

    void writeRegister(uint8_t reg, uint8_t value);

public:
    explicit PCA9685(uint8_t address);
    ~PCA9685();

    void setServoPulse(uint8_t channel, float pulse_ms);
    void addLeg(int ch0, int ch1, int ch2);
};

#endif // PCA9685_H
