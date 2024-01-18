#include <Arduino.h>
#include "EEPROM.h"

#include "pinout.h"
#include "settings.h"
#include "literals.h"

#include "globals/hardware.h"
#include "globals/state.h"

#include "states/diagnostic.h"
#include "states/home.h"
#include "states/sleep.h"
#include "states/countdown.h"
#include "states/celebrate.h"
#include "states/wish.h"
#include "states/goodbye.h"


void setup() {
    Serial.begin(9600);

    // Setup inputs:
    MICROPHONE.initPin(); // microphone pin
    DIAGNOSTIC_BUTTON.initPin(); // diagnostic button pin
    pinMode(WAKE_UP_INTERRUPT_PIN, INPUT_PULLUP); // wake up interrupt pin

    // Setup outputs:
    CANDLE_LED.initPin();  // candle LED pin
    FAILURE_LED.initPin(); // failure LED pin
    BUILTIN_LED.initPin(); // builtin LED pin
    BUZZER.initPin();      // buzzer pin

    LCD.init();        // initialize display
    LCD.clear();       // clear display
    LCD.noBacklight(); // disable display backlight

    // Initialize RTC module:
    if (!RTC.begin()) {
        FAILURE_LED.turnOn();

        LCD.backlight();
        LCD.displayError_P(ERROR_RTC_NOT_FOUND);

        while (true);
    }

    // Reset date and time to the firmware compilation date and time if needed:
    if (RTC_RESET) {
        const DateTime compilation_time = DateTime(F(__DATE__), F(__TIME__));
        RTC.adjust(compilation_time);

        LCD.backlight();
        LCD.displayInfo_P(INFO_RTC_ADJUSTED);

        /// after flashing firmware with RTC_RESET set to true and adjusting the datetime
        /// you need to rebuild and flash the firmware with RTC_RESET flag set to false.
        while (true);
    }

    // Check if DS3231 stopped due to power loss:
    if (RTC.lostPower()) {
        FAILURE_LED.turnOn();

        LCD.backlight();
        LCD.displayError_P(ERROR_RTC_LOST_POWER);

        while (true);
    }

    RTC.disable32K(); // disable 32K pin as it is not needed
    RTC.writeSqwPinMode(DS3231_OFF); // disable square wave generation on SQW pin as it is not needed

    // Reset both alarms:
    RTC.clearAlarm(1);
    RTC.clearAlarm(2);

    RTC.disableAlarm(2); // disable alarm 2 as only alarm 1 will be used

    // Set an alarm for the birthday date:
    if (!RTC.setAlarm1(BIRTH_DATE, DS3231_A1_Date)) {
        FAILURE_LED.turnOn();

        LCD.backlight();
        LCD.displayError_P(ERROR_RTC_SET_ALARM_FAILED);

        while (true);
    }

    // Reset index of the current wish to a custom value if needed:
    if (WISH_INDEX_RESET) {
        EEPROM.write(WISH_INDEX_EEPROM_ADDRESS, WISH_INDEX_RESET_TO);

        LCD.backlight();
        LCD.displayInfo_P(INFO_WISH_INDEX_RESET);

        while (true);
    }

    if (DIAGNOSTIC_BUTTON.isPressed()) { // if diagnostic button is pressed
//        Serial.println(F("info: jump to DIAGNOSTIC_SETUP"));
        ARDUINO_STATE = ArduinoState::DIAGNOSTIC_SETUP;
    } else {
//        Serial.println(F("info: jump to HOME_SETUP"));
        ARDUINO_STATE = ArduinoState::WISH_SETUP;
    }
}

void loop() {
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

            // Sleep states:
        case ArduinoState::SLEEP_SETUP:
            sleep_setup();
            break;
        case ArduinoState::SLEEP_LOOP:
            sleep_loop();
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
