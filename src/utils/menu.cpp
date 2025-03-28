#include "utils/menu.hpp"
#include "utils/utils.hpp"
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
        << " 3: Test functionalities\n"
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
            testingMenu();
            return;
    }
}

void testingMenu() {
    while (true) {
        std::cout 
        << '\n' << std::string(50, '_') << "\n" 
        << std::string(20, ' ') << "Testing Menu\n" 
        << std::string(50, '_')
        << "\n Welcome to the testing menu. Enter your selection:\n\n"
        << " 1: Test channel pulse\n"
        << " 2: Test camera\n"
        << " 3: Return to main menu\n"
        << std::string(50, '_') << "\n\n";
    
        short choice;
        std::cin >> choice;
        std::cin.ignore(1);
    
        switch (choice) {
            case 1:
                pulse(chips);
                break;
            case 2:
                camera();
                break;
            case 3:
                exitProgram();
                return;
        }
    }
}