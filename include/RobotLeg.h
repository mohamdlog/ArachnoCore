#ifndef ROBOTLEG_H
#define ROBOTLEG_H

#include <array>

struct RobotLeg {
    std::array<uint8_t, 3> channels;

    RobotLeg(uint8_t ch0, uint8_t ch1, uint8_t ch2) : channels{ch0, ch1, ch2} {}

    uint8_t& operator[](size_t index) {
        return channels[index];
    }

    const uint8_t& operator[](size_t index) const {
        return channels[index];
    }
};

#endif // ROBOTLEG_H