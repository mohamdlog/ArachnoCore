#pragma once

#include "../utils/PCA9685.hpp"

void pulse(std::vector<std::unique_ptr<PCA9685>>& chips);
void camera();