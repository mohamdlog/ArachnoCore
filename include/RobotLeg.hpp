#pragma once

#include <array>

struct RobotLeg {
    std::array<short, 3> channels;

    RobotLeg(short ch0, short ch1, short ch2) : channels{ch0, ch1, ch2} {}

    short& operator[](short index) {
        return channels[index];
    }

    const short& operator[](short index) const {
        return channels[index];
    }
};