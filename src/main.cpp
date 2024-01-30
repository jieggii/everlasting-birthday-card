#include <Arduino.h>
#include "EEPROM.h"

#include "pinout.h"
#include "settings.h"

#include "globals/hardware.h"
#include "globals/state.h"

#include "states/diagnostic.h"
#include "states/home.h"
#include "states/handle_alarm_interrupt.h"
#include "states/countdown.h"
#include "states/celebrate.h"
#include "states/wish.h"
#include "states/goodbye.h"

/// Handles DS3231 alarm interrupt: detaches interrupt pin to avoid
/// the ISR to be called again, puts Arduino into HANDLE_ALARM_INTERRUPT state.
void alarm_interrupt_handler() {
    detachInterrupt(digitalPinToInterrupt(WAKE_UP_INTERRUPT_PIN));

    // Change state to HANDLE_ALARM_INTERRUPT in order to check if the current month matches with the
    // birthday month. This logic is needed as DS3231 has no support for annual alarms.
    ARDUINO_STATE = ArduinoState::HANDLE_ALARM_INTERRUPT;
}

void setup() {
    Serial.begin(9600);

    // Setup outputs:
    LCD.init();        // initialize display
    LCD.clear();       // clear display
    LCD.noBacklight(); // disable display backlight

    CANDLE_LED.initPin();  // candle LED pin
    FAILURE_LED.initPin(); // failure LED pin
    BUILTIN_LED.initPin(); // builtin LED pin
    BUZZER.initPin();      // buzzer pin

    // Setup inputs:
    MICROPHONE.initPin(); // microphone pin
    CONTROL_BUTTON.initPin(); // diagnostic button pin
    pinMode(WAKE_UP_INTERRUPT_PIN, INPUT_PULLUP); // wake up interrupt pin

    // Initialize DS3231 RTC module:
    if (!RTC.begin()) {
        FAILURE_LED.turnOn();

        LCD.backlight();
        LCD.displayError(F("RTC not found"));

        while (true);
    }

    // Reset date and time to the firmware compilation date and time if needed:
    if (RTC_RESET) {
        const DateTime compilation_time = DateTime(F(__DATE__), F(__TIME__));
        RTC.adjust(compilation_time);

        LCD.backlight();
        LCD.displayInfo(F("RTC adjusted"));

        /// after flashing firmware with RTC_RESET set to true and adjusting the datetime
        /// you need to rebuild and flash the firmware with RTC_RESET flag set to false.
        while (true);
    }

    // Check if DS3231 stopped due to power loss:
    if (RTC.lostPower()) {
        FAILURE_LED.turnOn();

        LCD.backlight();
        LCD.displayError(F("RTC lost power"));

        while (true);
    }

    RTC.disable32K(); // disable 32K pin as it is not needed
    RTC.writeSqwPinMode(DS3231_OFF); // disable square wave generation on SQW pin as it is not needed

    // Reset alarm flags for both alarms:
    RTC.clearAlarm(1);
    RTC.clearAlarm(2);

    RTC.disableAlarm(2); // disable alarm 2 as only alarm 1 will be used

    // Set an alarm for the birthday date:
    if (!RTC.setAlarm1(BIRTH_DATE, DS3231_A1_Date)) {
        FAILURE_LED.turnOn();

        LCD.backlight();
        LCD.displayError(F("set alarm failed"));

        while (true);
    }

    // Attach an alarm interrupt handler:
    attachInterrupt(digitalPinToInterrupt(WAKE_UP_INTERRUPT_PIN), alarm_interrupt_handler, LOW);

    // Reset index of the current wish to a custom value if needed:
    if (WISH_INDEX_RESET) {
        EEPROM.write(WISH_INDEX_EEPROM_ADDRESS, WISH_INDEX_RESET_TO);

        LCD.backlight();
        LCD.displayInfo(F("wish index reset"));

        while (true);
    }

    if (CONTROL_BUTTON.isPressed()) {
        ARDUINO_STATE = ArduinoState::DIAGNOSTIC_SETUP;
    } else {
        ARDUINO_STATE = ArduinoState::HOME_SETUP;
    }
}

#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char* sbrk(int incr);
#else  // __ARM__
extern char *__brkval;
#endif  // __arm__

int freeMemory() {
    char top;
#ifdef __arm__
    return &top - reinterpret_cast<char*>(sbrk(0));
#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
    return &top - __brkval;
#else  // __arm__
    return __brkval ? &top - __brkval : &top - __malloc_heap_start;
#endif  // __arm__
}

void loop() {
//    Serial.println(freeMemory());
    switch (ARDUINO_STATE) {
        // Diagnostic states:
        case ArduinoState::DIAGNOSTIC_SETUP:
            diagnostic_setup();
            break;
        case ArduinoState::DIAGNOSTIC_LOOP:
            diagnostic_loop();
            break;

            // Home states:
        case ArduinoState::HOME_SETUP:
            home_setup();
            break;

        case ArduinoState::HOME_LOOP:
            home_loop();
            break;

            // Handle alarm interrupt state:
        case ArduinoState::HANDLE_ALARM_INTERRUPT:
            handle_alarm_interrupt();
            break;

            // Countdown states:
        case ArduinoState::COUNTDOWN_SETUP:
            countdown_setup();
            break;
        case ArduinoState::COUNTDOWN_LOOP:
            countdown_loop();
            break;

            // Celebrate states:
        case ArduinoState::CELEBRATE_SETUP:
            celebrate_setup();
            break;
        case ArduinoState::CELEBRATE_LOOP:
            celebrate_loop();
            break;

            // Wish states:
        case ArduinoState::WISH_SETUP:
            wish_setup();
            break;
        case ArduinoState::WISH_LOOP:
            wish_loop();
            break;

            // Goodbye states:
        case ArduinoState::GOODBYE_SETUP:
            goodbye_setup();
            break;
        case ArduinoState::GOODBYE_LOOP:
            goodbye_loop();
            break;
    }
}