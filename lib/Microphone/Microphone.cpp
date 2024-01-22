#include "Microphone.h"
#include "Arduino.h"


Microphone::Microphone(uint8_t pin) : pin(pin) {
    this->trigger_streak = 0;
};

void Microphone::initPin() const {
    pinMode(this->pin, INPUT);
}

bool Microphone::isTriggered(unsigned short treshold, uint8_t streak) {
    int reading = analogRead(this->pin);
    if (reading >=
        treshold) { // note: comparing signed value (reading) and unsigned (treshold) because we are 100% sure, that reading will never be negative
        this->trigger_streak += 1;
        if (this->trigger_streak == streak) {
            this->trigger_streak = 0;
            return true;
        } else {
            return false;
        }
    } else {
        this->trigger_streak = 0;
        return false;
    }
}