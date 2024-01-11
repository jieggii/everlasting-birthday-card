#include "Microphone.h"
#include "Arduino.h"


Microphone::Microphone(unsigned char pin) : pin(pin) {
    this->trigger_streak = 0;
};

void Microphone::initPin() const {
    pinMode(this->pin, INPUT);
}

bool Microphone::isTriggered(unsigned short treshold, unsigned short streak) {
    int reading = analogRead(this->pin);
    if (reading >= static_cast<int>(treshold)) {
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