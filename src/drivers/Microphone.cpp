#include "Microphone.h"
#include "Arduino.h"


Microphone::Microphone(unsigned short pin) {
    this->pin = pin;
};

void Microphone::init() {
    pinMode(this->pin, INPUT);
}

int Microphone::read() {
    return analogRead(this->pin);
}