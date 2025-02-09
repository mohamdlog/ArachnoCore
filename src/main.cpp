#include <vector>
#include "RobotConfig.h"
#include "MoverNode.h"

int main() {
    std::cout << "Enter the amount of PCA9685 chips you're using:\n";
    size_t pcaAmount;
    std::cin >> pcaAmount;

    std::vector<PCA9685> chips;

    for (size_t chip = 0; chip < pcaAmount; chip++) {
        chips.emplace_back(PCA9685(0x40 + chip));
    }

    for (auto& chip : chips) {
        setupPCA(chip);
    }

    move(chips);
}