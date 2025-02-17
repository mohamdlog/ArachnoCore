#include <format>
#include "PCA9685.hpp"

void PCA9685::writeRegister(uint8_t reg, uint8_t value) {
    if (i2c_smbus_write_byte_data(i2c_fd, reg, value) < 0) {
        std::cerr << "Failed to write to I2C device" << std::endl;
    }
}

void PCA9685::setServoPulse(uint8_t channel, float pulse_ms) {
    float pulse = pulse_ms * 4096 / 20; // Convert pulse time to 12-bit value
    uint16_t off_value = static_cast<uint16_t>(pulse);

    uint8_t off_low = 0x08 + (4 * (channel % 16));
    uint8_t off_high = 0x09 + (4 * (channel % 16));

    writeRegister(off_low, off_value & 0xFF);
    writeRegister(off_high, (off_value >> 8) & 0x0F);
}

PCA9685::PCA9685(uint8_t newAddress) : address(newAddress) {
    if ((i2c_fd = open(I2C_DEV, O_RDWR)) < 0) {
        std::cerr << "Failed to open I2C bus" << std::endl;
        return;
    }

    if (ioctl(i2c_fd, I2C_SLAVE, newAddress) < 0) {
        std::cerr << "Failed to set I2C address" << std::endl;
        return;
    }

    writeRegister(0x00, 0x10);  // Enter sleep mode
    writeRegister(0xFE, PRESCALER_50HZ); // Set prescaler
    writeRegister(0x00, 0x80);  // Wake up
    std::this_thread::sleep_for(std::chrono::milliseconds(5)); // Wait for oscillator
}

PCA9685::~PCA9685() {
    if (i2c_fd >= 0) close(i2c_fd);
}

void PCA9685::setChannelPulse(short leg, short channel, float pulse_ms) {
    uint8_t pulsed = legs[leg][channel];
    setServoPulse(pulsed, pulse_ms);
}

void PCA9685::addLeg(std::array<short, 3>& channels) {
    legs.emplace_back(RobotLeg(channels[0], channels[1], channels[2]));
}

std::string PCA9685::getAddress() {
    return std::format("0x{:02X}", address);
}

short PCA9685::legsAmount() const {
    return legs.size();
}
