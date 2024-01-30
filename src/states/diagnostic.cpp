#include "EEPROM.h"

#include "settings.h"
#include "literals.h"

#include "globals/state.h"
#include "globals/hardware.h"

#include "diagnostic.h"

unsigned short DIAGNOSTIC_DISPLAY_INTERVAL = 1000;
unsigned long DIAGNOSTIC_LAST_DISPLAY_MILLIS = 0;

void diagnostic_setup() {
    LCD.backlight(); // enable screen backlight

    // test hardware:
    CANDLE_LED.turnOn();
    FAILURE_LED.turnOn();
    BUZZER.tone(220);

    delay(150);

    CANDLE_LED.turnOff();
    FAILURE_LED.turnOff();
    BUZZER.noTone();

    ARDUINO_STATE = DIAGNOSTIC_LOOP;
}

void diagnostic_loop() {
    unsigned long current_millis = millis();
    if (current_millis - DIAGNOSTIC_LAST_DISPLAY_MILLIS >= DIAGNOSTIC_DISPLAY_INTERVAL) {
        // buffers holding information that will be displayed in the LCD:
        char row1[16 + 1];
        char row2[16 + 1];

        const DateTime now = RTC.now(); // current datetime
        const DateTime alarm = RTC.getAlarm1(); // alarm datetime
        const DateTime birthday = BIRTH_DATE.nextBirthday(now); // next birthday datetime

        if (CONTROL_BUTTON.isPressed()) {
            // screen 1 (next birthday datetime and alarm datetime):
            snprintf_P(
                    row1, sizeof(row1), DATE_FORMAT_LITERAL,
                    birthday.day(),
                    birthday.month(),
                    birthday.year() - 2000,
                    birthday.hour(),
                    birthday.minute(),
                    birthday.second()
            );
            snprintf(
                    row2, sizeof(row2), "%d.x.x %d:%d:%d",
                    alarm.day(),
                    alarm.hour(),
                    alarm.minute(),
                    alarm.second()
            );
        } else {
            // screen 1 (current datetime + wish index):
            snprintf_P(
                    row1, sizeof(row1), DATE_FORMAT_LITERAL,
                    now.day(),
                    now.month(),
                    now.year() - 2000,
                    now.hour(),
                    now.minute(),
                    now.second()
            );
            sprintf(row2, "Wish index: %d", EEPROM.read(WISH_INDEX_EEPROM_ADDRESS));
        }
        LCD.displayRows(row1, row2);
        DIAGNOSTIC_LAST_DISPLAY_MILLIS = current_millis;
    }
}
