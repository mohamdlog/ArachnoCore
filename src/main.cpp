#include "RobotConfig.h"

int main() {
    std::cout << "Are you using one or two PCA9685 chips? (1 | 2)\n";
    size_t pcaAmount;
    std::cin >> pcaAmount;

    PCA9685 pca1(0x40);
    PCA9685* pca2 = nullptr; 

    if (pcaAmount == 2) {
        pca2 = new PCA9685(0x41);
        configureLegs(pca1, pca2);
    } else {
        configureLegs(pca1);
    }
    
    for (size_t i = 0; i < pca1.legsAmount(); i++) {
        for (size_t j = 0; j < 3; j++) {
            pca1.setChannelPulse(i, j, 1.5);
        }
    }

    for (size_t i = 0; i < pca2->legsAmount(); i++) {
        for (size_t j = 0; j < 3; j++) {
            pca2->setChannelPulse(i, j, 1.5);
        }
    }
}