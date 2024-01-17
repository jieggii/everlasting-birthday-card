#include "LED.h"
#include "Arduino.h"

LED::LED(unsigned char pin) : pin(pin) {}

void LED::initPin() const {
    pinMode(this->pin, OUTPUT);
}

void LED::turnOn() {
    this->update_state(true);
}

void LED::turnOff() {
    this->update_state(false);
}

void LED::update_state(bool new_state) {
    digitalWrite(this->pin, new_state ? HIGH : LOW);
    this->is_powered = new_state;
}
