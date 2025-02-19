#include "utils/menu.hpp"
#include "nodes/test.hpp"
#include "core/config.hpp"

void mainMenu() {
    std::cout 
        << std::string(50, '_') << "\n" 
        << std::string(20, ' ') << "Main Menu\n" 
        << std::string(50, '_')
        << "\n Welcome to the main menu. Enter your selection:\n\n"
        << " 1: Read instructions\n"
        << " 2: Auto register from config.json\n"
        << " 3: Test movement\n"
        << std::string(50, '_') << "\n\n";

    short choice;
    std::cin >> choice;
    std::cin.ignore(1);

    switch (choice) {
        case 1:
            instructions();
            return;
        case 2:
            autoRegister();
            return;
        case 3:
            move(chips);
            return;
    }
}