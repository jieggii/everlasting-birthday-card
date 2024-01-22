#include "Arduino.h"

#include "Button.h"

Button::Button(uint8_t pin) : pin(pin) {}

/// Sets INPUT mode for the button pin.
void Button::initPin() const {
    pinMode(this->pin, INPUT);
}

/// Returns true if the button is pressed and false otherwise.
bool Button::isPressed() const {
    return digitalRead(this->pin) == HIGH;
}