#include <Arduino.h>
#include "EEPROM.h"

#include "pinout.h"

#include "settings.h"

#include "globals/hardware.h"
#include "globals/state.h"

#include "states/sleep.h"
#include "states/diagnostic.h"
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
    CANDLE_LED.init_pin(); // candle LED pin
    FAILURE_LED.init_pin(); // failure LED pin
    BUILTIN_LED.init_pin(); // builtin LED pin
    BUZZER.initPin(); // buzzer pin

    LCD.init(); // display
    LCD.noBacklight(); // disable LCD backlight

    // Boot delay:
    BUILTIN_LED.turn_on();
    delay(BOOT_DELAY);
    BUILTIN_LED.turn_off();

    // Initialize RTC:
    if (!RTC.begin()) {
        Serial.println("err: no RTC found");
        FAILURE_LED.turn_on();
        while (true);
    }

    // Set current date and time if DS3231 stopped due to power loss:
    if (RTC.lostPower()) {
        RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
        Serial.println(F("warn: RTC date has been updated"));
    }

    RTC.disable32K(); // disable 32K pin as it is not needed
    RTC.writeSqwPinMode(DS3231_OFF); // disable square wave generation on SQW pin as it is not needed

    // Reset both alarms:
    RTC.clearAlarm(1);
    RTC.clearAlarm(2);

    RTC.disableAlarm(2); // disable alarm 2 as only alarm 1 will be used

    // Set up an alarm
    DateTime alarmDate(
            2000, // year does not make any sense for the DS3231_A1_Date alarm mode, so let it be 2000 (the default one)
            5, // month does not make any sense for the DS3231_A1_Date alarm mode
            BIRTH_DAY,
            BIRTH_HOUR,
            BIRTH_MINUTE,
            BIRTH_SECOND
    );

    bool success = RTC.setAlarm1(alarmDate, DS3231_A1_Date);
    if (!success) {
        FAILURE_LED.turn_on();
        Serial.println(F("err: failed to set a new alarm"));
        while (true);
    }

    // Reset index of the current wish to a custom value if needed:
    if (WISH_INDEX_RESET) {
        EEPROM.write(WISH_INDEX_EEPROM_ADDRESS, WISH_INDEX_VALUE);
    }

    if (DIAGNOSTIC_BUTTON.isPressed()) { // if diagnostic button is pressed
        Serial.println(F("info: jump to DIAGNOSTIC_SETUP"));
        ARDUINO_STATE = ArduinoState::DIAGNOSTIC_SETUP;
    } else {
        Serial.println(F("info: jump to SLEEP_SETUP"));
        ARDUINO_STATE = ArduinoState::SLEEP_SETUP;
    }
}

void loop() {
    switch (ARDUINO_STATE) {
        // Sleep states:
        case ArduinoState::SLEEP_SETUP:
            sleep_setup();
            break;
        case ArduinoState::SLEEP_LOOP:
            sleep_loop();
            break;

            // Debug states:
        case ArduinoState::DIAGNOSTIC_SETUP:
            diagnostic_setup();
            break;
        case ArduinoState::DIAGNOSTIC_LOOP:
            diagnostic_loop();
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
