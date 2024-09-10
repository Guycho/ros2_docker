// PinReader.hpp
#ifndef PINREADER_HPP
#define PINREADER_HPP

#include <pigpio.h>

class PinReader {
public:
    // Constructor to initialize the pin
    PinReader(int pin) : pinNumber(pin) {
        if (gpioInitialise() < 0) {
            throw std::runtime_error("pigpio initialization failed");
        }
        gpioSetMode(pinNumber, PI_INPUT);
    }

    // Method to read the pin state
    int readPinState() {
        return gpioRead(pinNumber);
    }

    // Destructor to clean up resources
    ~PinReader() {
        gpioTerminate();
    }

private:
    int pinNumber;
};

#endif // PINREADER_HPP// PinReader.hpp
#ifndef PINREADER_HPP
#define PINREADER_HPP

#include <pigpio.h>

class PinReader {
public:
    // Constructor to initialize the pin
    PinReader(int pin) : pinNumber(pin) {
        if (gpioInitialise() < 0) {
            throw std::runtime_error("pigpio initialization failed");
        }
        gpioSetMode(pinNumber, PI_INPUT);
    }

    // Method to read the pin state
    int readPinState() {
        return gpioRead(pinNumber);
    }

    // Destructor to clean up resources
    ~PinReader() {
        gpioTerminate();
    }

private:
    int pinNumber;
};

#endif // PINREADER_HPP