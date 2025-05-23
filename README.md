# ArachnoCore: A Framework for Arachnid Robotics
ArachnoCore is a robotics framework designed for developing and controlling arachnid-inspired robots using Raspberry Pi and I2C/SPI communication protocols. This guide provides setup and configuration instructions for the hardware and software components.

## Prerequisites
- Raspberry Pi
- [Supported Chips](#supported-chips)
- [Recommended OS](https://ubuntu.com/download/raspberry-pi/thank-you?version=24.04.1&architecture=server-arm64+raspi)
- Dependencies:
    ```bash
    sudo apt-get install i2c-tools libi2c-dev
    ```

## Installation & Configuration
### 1. Enable I2C and Adjust Baud Rate
1. Edit the Raspberry Pi configuration file:
    ```bash
    sudo nano /boot/firmware/config.txt
    ```
2. Locate `dtparam=i2c_arm=on` and append the baud rate setting:
    ```
    dtparam=i2c_arm=on,i2c_arm_baudrate=400000
    ```
3. Reboot to apply changes:
    ```bash
    sudo reboot
    ```

### 2. SPI Configuration
- **Enable SPI** if your hardware requires it (e.g., sensors or peripherals using SPI).
- **Disable SPI** if using I2C/UART exclusively to avoid conflicts.

## Hardware Setup
### Supported Chips
| Component         | I2C Address |
|-------------------|--------------
| PCA9685 (Chip 1)  |  `0x40`
| PCA9685 (Chip 2)  |  `0x41`
| ADS7830           |  `0x48`
| MPU6050	        |  `0x68`

### Verify Connections
1. Scan for connected I2C devices"
    ```bash
    i2cdetect -y 1
    ```
2. Dump data from a specific address (e.g., PCA9685 at 0x40):
    ```bash
    i2cdump -y 1 0x40
    ```

## Software Setup
1. Compile the program (run in the project root directory):
   ```bash
   make
   ```
2. Run the program
   ```bash
   ./ArachnoCore
   ```

## Troubleshooting
- **SPI/I2C Conflicts:** Ensure only required protocols are enabled in /boot/firmware/config.txt.

- **Baud Rate Mismatch:** Confirm i2c_arm_baudrate=400000 is set if servos respond slowly.

- **Address Errors:** Verify hardware addresses match the detected results from i2cdetect.