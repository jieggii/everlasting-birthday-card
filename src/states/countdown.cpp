#include "settings.h"

#include "globals/state.h"
#include "globals/hardware.h"

#include "countdown.h"

void countdown_setup() {
    BUZZER.startTicking(
            COUNTDOWN_TICK_INTERVAL,
            COUNTDOWN_TICK_DURATION,
            COUNTDOWN_TICK_TONE,
            COUNTDOWN_TICK_COUNT
    );

    Serial.println(F("info: jump to COUNTDOWN_LOOP"));
    ARDUINO_STATE = ArduinoState::COUNTDOWN_LOOP;
}

void countdown_loop() {
    BUZZER.handle();
    if (BUZZER.getState() == BuzzerState::STANDBY) {
        Serial.println(F("info: jump to CELEBRATE_SETUP"));
        ARDUINO_STATE = ArduinoState::CELEBRATE_SETUP;
    }
}