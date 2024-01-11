#ifndef EVERLASTING_BIRTHDAY_CARD_HARDWARE_H
#define EVERLASTING_BIRTHDAY_CARD_HARDWARE_H

#include "SPI.h"
#include "RTClib.h"

#include "../lib/Buzzer/Buzzer.h"
#include "../lib/Microphone/Microphone.h"
#include "../lib/LED/LED.h"
#include "../lib/Display/Display.h"
#include "../lib/Button/Button.h"

/// The LCD used to display wishes and other text information.
extern Display LCD;

/// The microphone used to detect candle blowing.
extern Microphone MICROPHONE;

/// Buzzer which is used to play ticking sound and the happy birthday song.
extern Buzzer BUZZER;

/// Candle is a simple LED.
extern LED CANDLE_LED;

/// Failure LED is a led indicating failure.
extern LED FAILURE_LED;

/// Builtin LED is a builtin Arduino LED.
extern LED BUILTIN_LED;

extern Button DIAGNOSTIC_BUTTON;

/// Real time clock module used to keep track of time without power.
extern RTC_DS3231 RTC;

#endif //EVERLASTING_BIRTHDAY_CARD_HARDWARE_H
