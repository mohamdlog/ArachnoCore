#ifndef ROBOTCONFIG_H
#define ROBOTCONFIG_H

#include "PCA9685.h"
#include "RobotLeg.h"
#include <iostream>

void instructions();

void configureLegs(PCA9685 &pca, PCA9685 *pca2 = nullptr, int pcaAmount);

#endif // ROBOTCONFIG_H
