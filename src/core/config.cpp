#include <fstream>
#include "../external/json.hpp"
#include "core/config.hpp"

std::vector<std::unique_ptr<PCA9685>> chips;

void instructions() {
    std::cout 
        << "\n=== Arachnid Leg Channel Assignment Guide ===\n\n"
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

void prepareChips(short pcaAmount) {
    chips.reserve(pcaAmount);

    for (short chip = 0; chip < pcaAmount; chip++) {
        chips.emplace_back(std::make_unique<PCA9685>(0x40 + chip));
    }
}

void autoRegister() {
    nlohmann::json jsonObj;
    std::ifstream file("src/config.json");
    file >> jsonObj;

    prepareChips(jsonObj.size());

    std::array<short, 3> channels;

    for (auto& chip : chips) {
        const auto& legs = jsonObj[chip->getAddress()]["channels"];
    
        for (const auto& leg : legs) {
            std::tie(channels[0], channels[1], channels[2]) =
                std::make_tuple(leg[0].get<short>(), leg[1].get<short>(), leg[2].get<short>());
            chip->addLeg(channels);
        }
    }
    std::cout 
        << "Legs and channels have been automatically registered from config.json.\n"
        << "Returning to main menu...\n\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));
}