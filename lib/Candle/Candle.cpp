#include "Candle.h"
#include "Arduino.h"


Candle::Candle(unsigned short pin) {
    this->pin = pin;
    this->powered = false;
}

void Candle::init_pin() const {
    pinMode(this->pin, OUTPUT);
}

void Candle::turn_on() {
    this->update_state(true);
}

void Candle::turn_off() {
    this->update_state(false);
}

void Candle::update_state(bool new_state) {
    digitalWrite(this->pin, new_state ? HIGH : LOW);
    this->powered = new_state;
}
