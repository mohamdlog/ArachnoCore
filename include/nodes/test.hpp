#pragma once

#include "../utils/PCA9685.hpp"

void move(std::vector<std::unique_ptr<PCA9685>>& chips);