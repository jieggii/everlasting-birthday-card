#include "settings.h"

#include "globals/hardware.h"
#include "globals/state.h"

#include "check_month.h"


void check_month() {
    // clear alarm flag in order to set interrupt pin back to HIGH state:
    RTC.clearAlarm(1);

    // check if the current month matches with the birthday month:
    // (this logic is needed as DS3231 has no support for annual alarms)
    const DateTime now = RTC.now();
    if (now.month() == BIRTH_DATE.month()) {
        ARDUINO_STATE = ArduinoState::COUNTDOWN_SETUP;
    } else {
        ARDUINO_STATE = ArduinoState::HOME_LOOP;
    }
}