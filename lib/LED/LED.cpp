#include "Arduino.h"

#include "LED.h"

LED::LED(uint8_t pin) : pin(pin) {}

/// Sets OUTPUT mode for the LED's pin.
void LED::initPin() const {
    pinMode(this->pin, OUTPUT);
}

/// Turns on the LED.
void LED::turnOn() {
    this->update_state(true);
}

/// Turns off the LED.
void LED::turnOff() {
    this->update_state(false);
}

/// Updates state of the LED.
void LED::update_state(bool new_state) {
    digitalWrite(this->pin, new_state ? HIGH : LOW);
    this->is_powered = new_state;
}
