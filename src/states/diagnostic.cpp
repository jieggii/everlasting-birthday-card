#include "EEPROM.h"

#include "pinout.h"
#include "settings.h"
#include "literals.h"

#include "globals/state.h"
#include "globals/hardware.h"

#include "diagnostic.h"


void diagnostic_setup() {
    LCD.clear(); // clear the screen
    LCD.backlight(); // enable screen backlight


    CANDLE_LED.turnOn(); // turn on the candle to test it
    FAILURE_LED.turnOn(); // turn on the failure pin to test it
    BUZZER.tone(220); // make some noise using buzzer to test it

    delay(150);

    CANDLE_LED.turnOff();
    FAILURE_LED.turnOff();
    BUZZER.noTone();

    Serial.println(F("info: jump to DIAGNOSTIC_LOOP"));
    ARDUINO_STATE = DIAGNOSTIC_LOOP;
}

void diagnostic_loop() {
    const DateTime now = RTC.now(); // current datetime
    const DateTime alarm = RTC.getAlarm1(); // alarm datetime
    const DateTime birthday = BIRTH_DATE.nextBirthday(now); // next birthday datetime

    // buffers holding information that will be displayed on the LCD:
    char row1_buffer[16 + 1];
    char row2_buffer[16 + 1];

    // screen 1 (current datetime + wish index):
    snprintf_P(
            row1_buffer, sizeof(row1_buffer), DATE_FORMAT,
            now.day(),
            now.month(),
            now.year() - 2000,
            now.hour(),
            now.minute(),
            now.second()
    );
    sprintf(row2_buffer, "Wish index: %d", EEPROM.read(WISH_INDEX_EEPROM_ADDRESS));
    LCD.displayRows(row1_buffer, row2_buffer);
    delay(1500);
    LCD.clear();

    // screen 2 (next birthday datetime + alarm datetime):
    snprintf_P(
            row1_buffer, sizeof(row1_buffer), DATE_FORMAT,
            birthday.day(),
            birthday.month(),
            birthday.year() - 2000,
            birthday.hour(),
            birthday.minute(),
            birthday.second()
    );
    snprintf(
            row2_buffer, sizeof(row2_buffer), "%d.x.x %d:%d:%d",
            alarm.day(),
            alarm.hour(),
            alarm.minute(),
            alarm.second()
    );
    LCD.displayRows(row1_buffer, row2_buffer);
    delay(1500);
    LCD.clear();
}
