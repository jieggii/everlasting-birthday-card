#include "EEPROM.h"

#include "settings.h"

#include "globals/state.h"
#include "globals/hardware.h"

#include "wish.h"


void wish_setup() {
    // todo: fix wish index increment and handling logging
    uint8_t wishIndex = EEPROM.read(WISH_INDEX_EEPROM_ADDRESS);
    if (wishIndex > WISH_COUNT - 1) {
        wishIndex = static_cast<uint8_t>(0);
        Serial.println(F("warn: reset wish index to 0 as the stored one is out of range"));
    }
    // const short wishIndex = 0; // todo
    Serial.println("debug: wish with index " + String(wishIndex) + " will be displayed"); // todo remove

    // Display the current wish:
//    LCD.start_displaying(
//            WISH_LIST[wishIndex],
//            WISH_CAPTION,
//            WISH_DISPLAY_FIRST_FRAME_DURATION,
//            WISH_DISPLAY_FRAME_DURATION
//    );

    // Update stored wish index for the next wish to be displayed next time:
    uint8_t nextWishIndex = wishIndex + 1;
    if (nextWishIndex > WISH_COUNT - 1) {
        nextWishIndex = 0;
        Serial.println(F("warning: resetting stored wish index as the stored is out of range"));
    }
    EEPROM.write(WISH_INDEX_EEPROM_ADDRESS, nextWishIndex);

//    WISH_START_TS = millis();

    Serial.println(F("info: jump to WISH_LOOP"));
    ARDUINO_STATE = ArduinoState::WISH_LOOP;
}

void wish_loop() {
    LCD.handle(); // continue displaying the current wish
//    if (millis() - WISH_START_TS >= WISH_DURATION) { // if wish duration has expired
//        Serial.println("info: set state to SLEEP_COUNTDOWN_SETUP");
//        STATE = STATE_SLEEP_COUNTDOWN_SETUP;
//    }

}