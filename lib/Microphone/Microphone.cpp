#include "Microphone.h"
#include "Arduino.h"


Microphone::Microphone(unsigned short pin) {
    this->pin = pin;
};

void Microphone::init_pin() const {
    pinMode(this->pin, INPUT);
}

int Microphone::read() const {
    return analogRead(this->pin);
}

bool Microphone::is_triggered(unsigned short treshold, unsigned short streak) {
    int reading = this->read();
//    Serial.println(reading);
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