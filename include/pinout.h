#ifndef EVERLASTING_BIRTHDAY_CARD_PINOUT_H
#define EVERLASTING_BIRTHDAY_CARD_PINOUT_H

#include "pins_arduino.h"


/// Candle LED pin:
const uint8_t CANDLE_LED_PIN = 5;

/// Failure LED pin.
const uint8_t FAILURE_LED_PIN = 9;

/// Piezo buzzer pin:
const uint8_t BUZZER_PIN = 4;

/// Microphone pin:
const uint8_t MICROPHONE_PIN = A5;

/// Pin used for wake up interruption.
const uint8_t WAKE_UP_INTERRUPT_PIN = 7;

/// Debug button pin.
const uint8_t DIAGNOSTIC_BUTTON_PIN = 8;

/// I2C address of the 16x2 LCD.
const uint8_t LCD_ADDRESS = 0x27;

#endif //EVERLASTING_BIRTHDAY_CARD_PINOUT_H
