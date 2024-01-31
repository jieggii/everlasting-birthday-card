#include "settings.h"
#include "globals/hardware.h"
#include "globals/state.h"

#include "handle_alarm_interrupt.h"

void handle_alarm(bool triggered_by_interrupt) {
    // clear alarm flag in order to set interrupt pin back to the default state
    // if handle_alarm function was called by interrupt:
    if (triggered_by_interrupt) {
        RTC.clearAlarm(1);
    }

    // check if the current month matches with the birthday month:
    // (this logic is needed as DS3231 has no support for annual alarms,
    // so alarms happen every month)
    const DateTime now = RTC.now();
    if (now.month() == BIRTH_DATE.month()) {
        ARDUINO_STATE = ArduinoState::COUNTDOWN_SETUP;
    } else {
        if (triggered_by_interrupt) {
            // if handler is called by interrupt, then home_setup() has already been run,
            // so we just need to go back into HOME_LOOP
            ARDUINO_STATE = ArduinoState::HOME_LOOP;
        } else {
            // if handler is not called by interrupt, then home_setup() has not been run yet.
            ARDUINO_STATE = ArduinoState::HOME_SETUP;
        }
    }
}