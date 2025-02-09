#ifndef ROBOTLEG_H
#define ROBOTLEG_H

#include <array>
#include <cstddef>

struct RobotLeg {
    std::array<int, 3> channels;

    RobotLeg(int ch0, int ch1, int ch2) : channels{ch0, ch1, ch2} {}

    int& operator[](size_t index) {
        return channels[index];
    }

    const int& operator[](size_t index) const {
        return channels[index];
    }
};

#endif // ROBOTLEG_H