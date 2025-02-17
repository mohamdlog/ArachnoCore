#pragma once

#include "PCA9685.hpp"

extern std::vector<std::unique_ptr<PCA9685>> chips;

void prepareChips();
void instructions();
void autoRegister();
void manualRegister();