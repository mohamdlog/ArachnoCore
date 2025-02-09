#include <sstream>
#include "MoverNode.h"

void move(std::vector<PCA9685> chips) {
    std::cout
            << "\n=== For testing purpose ===\n\n"
            << "Enter PCA9865 chip number, leg number, channel number,\n"
            << "and pulse width in milliseconds to control movement.\n"
            << "Example Input: 2 1 0 1.5 Press Enter at anytime to exit.\n\n";
    std::cin.ignore(1);

    while (true) {
        std::cout << "Input: ";
        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "Exiting...\n";
            break;
        }

        std::istringstream iss(input);
        size_t chipNumber, leg, channel;
        float pulse;

        if (iss >> chipNumber >> leg >> channel >> pulse) {
            chips[chipNumber].setChannelPulse(leg, channel, pulse);
            std::cout 
                << "Leg " << leg << ", channel " << channel 
                << " on chip " << chips[chipNumber-1].getAddress()
                << " received a " << pulse << " ms pulse.\n\n";
        } else {
            std::cout << "Invalid input, please enter four numbers.\n";
        }
    }
}