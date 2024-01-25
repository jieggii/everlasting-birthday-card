#include "settings.h"

#include "globals/state.h"
#include "globals/hardware.h"

#include "goodbye.h"

void goodbye_setup() {
    LCD.clear();

    char buffer[strlen_P(GOODBYE_TEXT) + 1];
    strcpy_P(buffer, GOODBYE_TEXT);
    LCD.initScrolling(buffer, 1);

    ARDUINO_STATE = ArduinoState::GOODBYE_LOOP;
}

void goodbye_loop() {
    LCD.handleScrolling(1000, 500);
    if (!LCD.isScrolling()) {
        LCD.noBacklight();
        delay(1500);
        ARDUINO_STATE = ArduinoState::HOME_SETUP;
    }
}
