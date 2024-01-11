#include "LED.h"
#include "Arduino.h"

LED::LED(unsigned char pin) : pin(pin) {}

void LED::init_pin() const {
    pinMode(this->pin, OUTPUT);
}

void LED::turn_on() {
    this->update_state(true);
}

void LED::turn_off() {
    this->update_state(false);
}

void LED::update_state(bool new_state) {
    digitalWrite(this->pin, new_state ? HIGH : LOW);
    this->is_powered = new_state;
}
