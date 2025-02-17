#include <vector>
#include "RobotConfig.hpp"
#include "MoverNode.hpp"

int main() {
    std::cout << "Enter the amount of PCA9685 chips you're using:\n";
    size_t pcaAmount;
    std::cin >> pcaAmount;

    std::vector<std::unique_ptr<PCA9685>> chips;
    chips.reserve(pcaAmount);

    for (size_t chip = 0; chip < pcaAmount; chip++) {
        chips.emplace_back(std::make_unique<PCA9685>(0x40 + chip));
    }

    for (auto& chip : chips) {
        setupPCA(*chip);
    }

    move(chips);
}