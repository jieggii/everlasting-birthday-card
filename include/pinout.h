#ifndef EVERLASTING_BIRTHDAY_CARD_PINOUT_H
#define EVERLASTING_BIRTHDAY_CARD_PINOUT_H

#include "Arduino.h"

/// Candle LED pin:
const unsigned char CANDLE_LED_PIN = 5;

/// Failure LED pin.
const unsigned char FAILURE_LED_PIN = 9;

/// Piezo buzzer pin:
const unsigned char BUZZER_PIN = 4;

/// Microphone pin:
const unsigned char MICROPHONE_PIN = A5;

/// Pin used for wake up interruption.
const unsigned char WAKE_UP_INTERRUPT_PIN = 7;

/// Debug button pin.
const unsigned char DIAGNOSTIC_BUTTON_PIN = 8;

const uint8_t LCD_ADDRESS = 0x27;


#endif //EVERLASTING_BIRTHDAY_CARD_PINOUT_H
