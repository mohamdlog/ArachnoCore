#include "utils/utils.hpp"

void exitProgram() {
    std::cout << "\nReturning to menu...\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1250));
}

std::string checkExit() {
    std::cout << "\nInput: (Enter to exit) ";
    std::string input;
    std::getline(std::cin, input);

    if (input.empty()) {
        exitProgram();
        return "";
    }
    
    return input;
}