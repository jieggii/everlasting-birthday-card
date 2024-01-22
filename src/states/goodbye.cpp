#include "globals/state.h"
#include "globals/hardware.h"

#include "goodbye.h"

// todo: display something like "see you in the next year" for 5 sec


void goodbye_setup() {
}

void goodbye_loop() {
    ARDUINO_STATE = ArduinoState::HOME_SETUP;
}
