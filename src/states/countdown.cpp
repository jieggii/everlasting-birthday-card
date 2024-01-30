#include "settings.h"

#include "globals/state.h"
#include "globals/hardware.h"

#include "countdown.h"


void countdown_setup() {
    // clear the screen disable backlight:
    LCD.clear();
    LCD.noBacklight();

    // start ticking using buzzer:
    BUZZER.initTick(
            COUNTDOWN_TICK_INTERVAL,
            COUNTDOWN_TICK_DURATION,
            COUNTDOWN_TICK_TONE,
            COUNTDOWN_TICKS_COUNT
    );

    ARDUINO_STATE = ArduinoState::COUNTDOWN_LOOP;
}

void countdown_loop() {
    BUZZER.handle(); // play ticking sound
    if (BUZZER.getState() == BuzzerState::STANDBY) { // if the buzzer has ticked desired number of times:
        ARDUINO_STATE = ArduinoState::CELEBRATE_SETUP;
    }
}