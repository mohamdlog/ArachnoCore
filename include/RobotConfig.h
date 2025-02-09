#ifndef ROBOTCONFIG_H
#define ROBOTCONFIG_H

#include "PCA9685.h"

void instructions();

void configureLegs(PCA9685 &pca, PCA9685 *pca2 = nullptr);

#endif // ROBOTCONFIG_H
