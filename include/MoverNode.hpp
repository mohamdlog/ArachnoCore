#pragma once

#include <memory>
#include "PCA9685.hpp"

void move(std::vector<std::unique_ptr<PCA9685>>& chips);