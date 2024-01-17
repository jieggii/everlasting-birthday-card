
#include "settings.h"
#include "literals.h"

#include "globals/hardware.h"
#include "globals/state.h"

#include "home.h"


const char text[] PROGMEM = "hello world! This is a very long text...";

void home_setup() {
    LCD.backlight();
    ARDUINO_STATE = ArduinoState::HOME_LOOP;


    char text_buffer[41];
    strcpy_P(text_buffer, text);
    Serial.println(text_buffer);
    LCD.displayError_P(ERROR_RTC_LOST_POWER);
//    LCD.initScrolling(text_buffer, 2);
}

//void home_loop() {
//    const DateTime now = RTC.now();
//    const DateTime birthday = BIRTH_DATE.nextBirthday(now);
//    const TimeSpan time_left = birthday - now;
//
//    char row1[16 + 1];
//    char row2[16 + 1];
//
//    sprintf(row1, "Do DR: %d dnei,", time_left.days());
//    sprintf(row2, "    %02d:%02d:%02d    ", time_left.hours(), time_left.minutes(), time_left.seconds());
//    LCD.displayRows(row1, row2);
//    delay(1000);
//}

void home_loop() {
//    LCD.handleScrolling(1000, 500);
}
