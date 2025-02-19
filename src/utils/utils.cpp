#include "utils/utils.hpp"

void exitProgram() {
    std::cout << "\nExiting to main menu...\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

std::string checkExit() {
    std::cout << "\nInput: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.empty()) {
        exitProgram();
        return "";
    }
    
    return input;
}