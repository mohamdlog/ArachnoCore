#include "PCA9685.h"
#include "RobotConfig.h"
#include <iostream>

int main() {
    std::cout << "Are you using one or two PCA9685 chips? (1 | 2) ";
    int pcaAmount;
    std::cin >> pcaAmount;

    PCA9685 pca1(0x40);
    PCA9685* pca2 = nullptr; 

    if (pcaAmount == 2) {
        pca2 = new PCA9685(0x41);
    }
    
}