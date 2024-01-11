#include "Arduino.h"

#include "Button.h"

Button::Button(unsigned char pin) : pin(pin) {}

void Button::initPin() const {
    pinMode(this->pin, INPUT);
}

bool Button::isPressed() const {
    return digitalRead(this->pin) == 1;
}