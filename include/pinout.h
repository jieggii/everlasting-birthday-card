#ifndef EVERLASTING_BIRTHDAY_CARD_PINOUT_H

#include "Arduino.h"

// Microphone pin:
const unsigned short MICROPHONE_PIN = A1;

// Piezo buzzer pin:
const unsigned short BUZZER_PIN = 4;

// Candle LED pin:
const unsigned short CANDLE_PIN = 5;

// 1602 LCD configuration:
const unsigned short LCD_ADDRESS = 0x27;

// DS3231 RTC module configuration:
//const unsigned short RTC_ADDRESS = 0x68;

/// Pin used for wake up interruption.
const unsigned short WAKE_UP_INTERRUPT_PIN = 7;


#define EVERLASTING_BIRTHDAY_CARD_PINOUT_H

#endif //EVERLASTING_BIRTHDAY_CARD_PINOUT_H
