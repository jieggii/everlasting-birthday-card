#include "pins_arduino.h"

#include "RTClib.h"

#include "../lib/Buzzer/Buzzer.h"
#include "../lib/Microphone/Microphone.h"
#include "../lib/LED/LED.h"
#include "../lib/Display/Display.h"
#include "../lib/Button/Button.h"


#include "pinout.h"


Display LCD(LCD_ADDRESS, 16, 2);
Microphone MICROPHONE(MICROPHONE_PIN);
Buzzer BUZZER(BUZZER_PIN);
LED CANDLE_LED(CANDLE_LED_PIN);
LED FAILURE_LED(FAILURE_LED_PIN);
LED BUILTIN_LED(LED_BUILTIN);
Button DIAGNOSTIC_BUTTON(DIAGNOSTIC_BUTTON_PIN);
RTC_DS3231 RTC;
