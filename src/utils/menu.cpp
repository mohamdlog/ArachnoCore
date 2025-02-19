#include "utils/menu.hpp"
#include "nodes/test.hpp"
#include "core/config.hpp"

void mainMenu() {
    std::cout 
        << std::string(50, '_') << "\n" 
        << std::string(20, ' ') << "Main Menu\n" 
        << std::string(50, '_')
        << "\n Welcome to the main menu. Enter your selection:\n\n"
        << " 1: Auto register chips and channels from config.json\n"
        << " 2: Manually register chips and channels\n"
        << " 3: Test movement\n"
        << std::string(50, '_') << "\n\n";

    short choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            autoRegister();
            return;
        case 2:
            return;
        case 3:
            move(chips);
            return;
    }
}