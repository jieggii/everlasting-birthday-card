#include "settings.h"

#include "globals/state.h"
#include "globals/hardware.h"

#include "goodbye.h"


void goodbye_setup() {
    LCD.clear();

    char buffer[GOODBYE_TEXT_BUFSIZE];
    strcpy_P(buffer, GOODBYE_TEXT);

    LCD.initScrolling(buffer, 1);
    ARDUINO_STATE = ArduinoState::GOODBYE_LOOP;
}

void goodbye_loop() {
    LCD.handleScrolling(LCD_SCROLLING_FIRST_FRAME_DURATION, LCD_SCROLLING_FIRST_FRAME_DURATION);
    if (!LCD.isScrolling()) {
        LCD.noBacklight();
        delay(1500);
        ARDUINO_STATE = ArduinoState::HOME_SETUP;
    }
}
