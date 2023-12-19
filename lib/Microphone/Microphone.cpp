#include "Microphone.h"
#include "Arduino.h"


Microphone::Microphone(unsigned short pin, unsigned short trigger_treshold, unsigned short target_trigger_streak) {
    this->pin = pin;
    this->trigger_treshold = trigger_treshold;
    this->target_trigger_streak = target_trigger_streak;
};

void Microphone::init() {
    pinMode(this->pin, INPUT);
}

int Microphone::read() {
    return analogRead(this->pin);
}

bool Microphone::check_trigger() {
    int reading = this->read();
    if (reading == this->trigger_treshold) {
        this->trigger_streak += 1;
        if (this->trigger_streak == this->target_trigger_streak) {
            return true;
        } else {
            return false;
        }

    } else {
        this->trigger_streak = 0;
        return false;
    }
}