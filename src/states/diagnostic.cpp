#include "EEPROM.h"

#include "pinout.h"
#include "settings.h"

#include "globals/state.h"
#include "globals/hardware.h"

#include "diagnostic.h"


void diagnostic_setup() {
    CANDLE_LED.turn_on(); // turn on the candle to test it
    FAILURE_LED.turn_on(); // turn on the failure pin to test it
    tone(BUZZER_PIN, 443); // make some noise using buzzer to test it

    delay(100);

    CANDLE_LED.turn_off();
    FAILURE_LED.turn_off();
    noTone(BUZZER_PIN);

    LCD.backlight(); // enable screen backlight

    Serial.println(F("info: jump to DIAGNOSTIC_LOOP"));
    ARDUINO_STATE = DIAGNOSTIC_LOOP;
}

void diagnostic_loop() {
    // todo: use PROGMEM
    DateTime now = RTC.now();
    DateTime alarm = RTC.getAlarm1();

    LCD.clear();
    LCD.print(
            String(now.month()) + "." +
            String(now.day()) + "." +
            String(now.year() - 2000) + " " +
            String(now.hour()) + ":" +
            String(now.minute()) + ":" +
            String(now.second())
    );

    LCD.setCursor(0, 1);
    LCD.print(
            "xx." + String(alarm.day()) +
            ".xx " + String(alarm.hour()) +
            ":" + String(alarm.minute()) +
            ":" + String(alarm.second())
    );


    delay(5000);

    LCD.clear();
    LCD.print("Next wish: #" + String(EEPROM.read(WISH_INDEX_EEPROM_ADDRESS)));

    delay(1000);
}
