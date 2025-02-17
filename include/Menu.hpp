#pragma once

#include <memory>
#include "RobotConfig.hpp"

extern std::vector<std::unique_ptr<PCA9685>> chips;

void prepareChips();
void autoRegister();
void manualRegister();
void mainMenu();
