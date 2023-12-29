#include "Candle.h"
#include "Arduino.h"


Candle::Candle(unsigned short pin) {
    this->pin = pin;
}

void Candle::init() const {
    pinMode(this->pin, OUTPUT);
}

void Candle::turn_on() {
    this->set_powered(true);
}

void Candle::turn_off() {
    this->set_powered(false);
}

void Candle::set_powered(bool new_state) {
    if (new_state) {
        digitalWrite(this->pin, HIGH);
    } else {
        digitalWrite(this->pin, LOW);
    }
    this->powered = new_state;
}