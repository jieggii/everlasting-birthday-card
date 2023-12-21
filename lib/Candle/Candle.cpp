#include "Candle.h"
#include "Arduino.h"


Candle::Candle(unsigned short pin) {
    this->pin = pin;
}

void Candle::init() const {
    pinMode(this->pin, OUTPUT);
}

void Candle::set_powered(bool new_state) {
    if (new_state) {
        digitalWrite(this->pin, HIGH);
    } else {
        digitalWrite(this->pin, LOW);
    }
    this->powered = new_state;
}