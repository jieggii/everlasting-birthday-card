#include "pins_arduino.h"

#include "RTClib.h"

#include "Buzzer.h"
#include "Microphone.h"
#include "LED.h"
#include "Display.h"
#include "Button.h"

#include "pinout.h"


Display LCD(LCD_ADDRESS, 16, 2);
Microphone MICROPHONE(MICROPHONE_PIN);
Buzzer BUZZER(BUZZER_PIN);
LED CANDLE_LED(CANDLE_LED_PIN);
LED FAILURE_LED(FAILURE_LED_PIN);
Button CONTROL_BUTTON(DIAGNOSTIC_BUTTON_PIN);
RTC_DS3231 RTC;
