#ifndef EVERLASTING_BIRTHDAY_CARD_PINOUT_H

#include "Arduino.h"

/// Candle LED pin:
const unsigned short CANDLE_LED_PIN = 5;

/// Failure LED pin.
const unsigned short FAILURE_LED_PIN = 9;

/// Piezo buzzer pin:
const unsigned short BUZZER_PIN = 4;

/// 16x2 LCD i2c address:
const unsigned short LCD_ADDRESS = 0x27;

/// Microphone pin:
const unsigned short MICROPHONE_PIN = A1;

/// Pin used for wake up interruption.
const unsigned short WAKE_UP_INTERRUPT_PIN = 7;

/// Debug button pin.
const unsigned short DEBUG_BUTTON_PIN = 8;


#define EVERLASTING_BIRTHDAY_CARD_PINOUT_H

#endif //EVERLASTING_BIRTHDAY_CARD_PINOUT_H
