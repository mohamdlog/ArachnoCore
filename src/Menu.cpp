#include "Menu.hpp"

std::vector<std::unique_ptr<PCA9685>> chips;

void prepareChips() {
    std::cout << "Enter the amount of PCA9685 chips you're using:\n";
    size_t pcaAmount;
    std::cin >> pcaAmount;

    chips.reserve(pcaAmount);

    for (size_t chip = 0; chip < pcaAmount; chip++) {
        chips.emplace_back(std::make_unique<PCA9685>(0x40 + chip));
    }
}

void autoRegister() {
    for (auto& chip : chips) {
        loadFile(*chip);
    }
    std::cout << "Channels successfully loaded from config.json.\n";
}

void manualRegister() {
    for (auto& chip : chips) {
        setupPCA(*chip);
    }
    std::cout << "Channels successfully registered.\n";
}

void mainMenu() {
    std::cout 
        << std::string(50, '_') << "\n" 
        << std::string(20, ' ') << "Main Menu\n" 
        << std::string(50, '_')
        << "\n Welcome to the main menu. Enter your selection:\n\n"
        << " 1: Auto register channels from config.json\n"
        << " 2: Manually register channels\n"
        << " 3: Test movement\n";

    size_t choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            autoRegister();
            return;
        case 2:
            manualRegister();
            return;
        case 3:
            move(chips);
            return;
    }
}