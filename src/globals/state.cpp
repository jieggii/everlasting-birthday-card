#include "state.h"

// SLEEP_SETUP is the default state meaning that Arduino
// will be put into the power down mode right after boot.
ArduinoState ARDUINO_STATE = ArduinoState::SLEEP_SETUP;
