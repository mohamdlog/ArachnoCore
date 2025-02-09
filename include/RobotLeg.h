#ifndef ROBOTLEG_H
#define ROBOTLEG_H

#include <array>

struct RobotLeg {
    std::array<size_t, 3> channels;

    RobotLeg(size_t ch0, size_t ch1, size_t ch2) : channels{ch0, ch1, ch2} {}

    size_t& operator[](size_t index) {
        return channels[index];
    }

    const size_t& operator[](size_t index) const {
        return channels[index];
    }
};

#endif // ROBOTLEG_H