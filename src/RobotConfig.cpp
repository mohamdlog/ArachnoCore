#include "PCA9685.h"
#include "RobotLeg.h"
#include <iostream>
#include <map>

void instructions() {
    std::cout 
        << "=== Arachnid Leg Channel Assignment Guide ===\n\n"
        << "Each arachnid leg consists of three servo channels:\n"
        << "  - Base     (Channels: 0, 3, 6, ...)\n"
        << "  - Shoulder (Channels: 1, 4, 7, ...)\n"
        << "  - Arm      (Channels: 2, 5, 8, ...)\n\n"
        
        << "When entering channels, follow this pattern:\n"
        << "  - Leg 1: Base = Channel 0, Shoulder = Channel 1, Arm = Channel 2\n"
        << "  - Leg 2: Base = Channel 3, Shoulder = Channel 4, Arm = Channel 5\n"
        << "  - Leg 3: Base = Channel 6, Shoulder = Channel 7, Arm = Channel 8\n\n"
        
        << "If using multiple PCA9685 chips:\n"
        << "  - Each PCA9685 chip has 16 physical channels, numbered 0-15 in hardware.\n"
        << "  - The first PCA9685 (I2C address 0x40) controls Channels 0-15.\n"
        << "  - The second PCA9685 (I2C address 0x41) controls Channels 16-31 in software,\n"
        << "    but physically, it still maps to channels 0-15 on that chip.\n"
        << "  - This means that when reading hardware registers, you only ever see values 0-15,\n"
        << "    because each PCA9685 independently addresses its own 16 channels.\n"
        << "  - You can enter either logical or hardware channel numbers, and the software\n"
        << "    will automatically map them to the correct hardware registers.\n\n"
        
        << "To enter channel assignments correctly:\n"
        << "  - Turn the arachnid so it is facing you.\n"
        << "  - Follow the numbering pattern above, starting with Leg 1 on your right side\n"
        << "    (which corresponds to the arachnid's left side).\n\n"
        
        << "Video guide coming soon!\n"
        << std::endl;
}

void configureLegs(PCA9685 &pca, PCA9685 *pca2 = nullptr, int pcaAmount) {
    instructions();

    std::cout << "Enter total amount of legs to configure:\n";
    int legsAmount, currentLeg = 1;
    std::cin >> legsAmount;

    std::cout << "Setting up channels at address 0x40. Press Enter anytime to complete setup.";

    for (; currentLeg < legsAmount; currentLeg++) {
        std::cout << "\nEnter the 3 channels for leg " << currentLeg << ", each seperated by a space: ";
        int ch0, ch1, ch2;
        if (!(std::cin >> ch0 >> ch1 >> ch2)) {
            std::cout << "Exiting...\n";
            break;
        }
        pca.addLeg(ch0, ch1, ch2);
    }

    if (pca2) {
        std::cout << "Setting up channels at address 0x41. Press Enter anytime to complete setup.";
        for (; currentLeg < legsAmount; currentLeg++) {
            std::cout << "\nEnter the 3 channels for leg " << currentLeg << ", each seperated by a space: ";
            int ch0, ch1, ch2;
            if (!(std::cin >> ch0 >> ch1 >> ch2)) {
                std::cout << "Exiting...\n";
                break;
            }
            pca.addLeg(ch0, ch1, ch2);
        }
    }
}