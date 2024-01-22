#include "EEPROM.h"

#include "settings.h"

#include "globals/state.h"
#include "globals/hardware.h"

#include "wish.h"


void wish_setup() {
    // Calculate number of wishes stored in the PROGMEM:
    uint8_t wishes_count = 0;
    while (pgm_read_ptr(&WISHES[wishes_count]) != nullptr) {
        wishes_count++;
    }

    // Read current wish index:
    uint8_t wish_index = EEPROM.read(WISH_INDEX_EEPROM_ADDRESS);

    // Reset current wish index to 0 if it is out-of-bound:
    if (wish_index >= wishes_count) {
        wish_index = 0;
        Serial.println(F("warn: reset wish index to 0 as the stored one is out of range")); // todo remove
    }
    Serial.println("debug: wish with index " + String(wish_index) + " will be displayed"); // todo remove

    // Read current wish and put it into a buffer:
    const char *wish = reinterpret_cast<const char *>(pgm_read_ptr(&WISHES[wish_index]));
    char buffer[sizeof wish + 1];
    strcpy_P(buffer, wish);

    // Initialize wish scrolling on the LCD:
    LCD.initScrolling(buffer, WISH_DISPLAY_COUNT);

    // Update stored wish index for the next wish to be displayed next time:
    EEPROM.write(WISH_INDEX_EEPROM_ADDRESS, wish_index + 1);

    Serial.println(F("info: jump to WISH_LOOP"));
    ARDUINO_STATE = ArduinoState::WISH_LOOP;
}

void wish_loop() {
    LCD.handleScrolling(LCD_SCROLLING_FIRST_FRAME_DURATION, LCD_SCROLLING_FRAME_DURATION);
    if (!LCD.isScrolling()) { // if finished scrolling the wish desired number of times
        ARDUINO_STATE = ArduinoState::GOODBYE_SETUP;
    }
}