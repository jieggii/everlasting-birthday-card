#include "Candle.h"
#include "Arduino.h"


Candle::Candle(unsigned short pin) {
    this->pin = pin;
}

void Candle::init() {
    pinMode(this->pin, OUTPUT);
}

void Candle::set_state(bool state) {
    if (state) {
        digitalWrite(this->pin, HIGH);
    } else {
        digitalWrite(this->pin, LOW);
    }
}