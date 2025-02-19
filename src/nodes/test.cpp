#include "nodes/test.hpp"
#include "utils/utils.hpp"

void move(std::vector<std::unique_ptr<PCA9685>>& chips) {
    std::cout
            << "\n=== For testing purposes ===\n\n"
            << "Enter PCA9865 chip number, leg number, channel number,\n"
            << "and pulse width in milliseconds to test movement.\n"
            << "Press Enter at anytime to exit.\nExample Input: 2 1 0 1.5\n";
    
    std::string input;

    while (!(input = checkExit()).empty()) {
        std::istringstream iss(input);
        unsigned short chipNumber, leg, channel;
        float pulse;
    
        if (chips.size() == 0) {
            std::cout << "Warning: No chips registered. Please return to main menu and register chips.\n";
            exitProgram();
            return;
        }

        if (!(iss >> chipNumber >> leg >> channel >> pulse)) {
            std::cout << "Invalid input, please enter four numbers.\n";
            continue;
        }
    
        if (chipNumber == 0 || chipNumber > chips.size()) {
            std::cout << "Error: chipNumber is out of bounds. The limit is " << chips.size() << ".\n";
            continue;
        }
    
        chips[chipNumber - 1]->setChannelPulse(leg-1, channel, pulse);
        std::cout 
            << "leg " << leg << ", channel " << channel 
            << " on chip " << chips[chipNumber - 1]->getAddress()
            << " received a " << pulse << "ms pulse.\n\n";
    }
}
    