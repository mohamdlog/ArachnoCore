#ifndef ROBOTLEG_H
#define ROBOTLEG_H

#include <array>

struct RobotLeg {
    std::array<int, 3> channels;

    RobotLeg(int ch0, int ch1, int ch2) : channels{ch0, ch1, ch2} {}
};

#endif // ROBOTLEG_H