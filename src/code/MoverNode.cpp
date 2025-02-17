#include <sstream>
#include "MoverNode.hpp"

void move(std::vector<std::unique_ptr<PCA9685>>& chips) {
    std::cout
            << "\n=== For testing purpose ===\n\n"
            << "Enter PCA9865 chip number, leg number, channel number,\n"
            << "and pulse width in milliseconds to control movement.\n"
            << "Press Enter at anytime to exit.\nExample Input: 2 1 0 1.5\n";
    std::cin.ignore(1);

    while (true) {
        std::cout << "\nInput: ";
        std::string input;
        std::getline(std::cin, input);
    
        if (input.empty()) {
            std::cout << "Exiting...\n";
            return;
        }
    
        std::istringstream iss(input);
        size_t chipNumber, leg, channel;
        float pulse;
    
        if (!(iss >> chipNumber >> leg >> channel >> pulse)) {
            std::cout << "Invalid input, please enter four numbers.\n";
            continue;
        }
    
        if (chipNumber == 0 || chipNumber > chips.size()) {
            std::cout << "Error: chipNumber is out of bounds. Valid range is 1 to " << chips.size() << ".\n";
            continue;
        }
    
        chips[chipNumber - 1]->setChannelPulse(leg-1, channel, pulse);
        std::cout 
            << "leg " << leg << ", channel " << channel 
            << " on chip " << chips[chipNumber - 1]->getAddress()
            << " received a " << pulse << "ms pulse.\n\n";
    }
}
    