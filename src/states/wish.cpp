#include "EEPROM.h"

#include "settings.h"
#include "songs/undertale_once_upon_a_time.h"
#include "songs/birthday.h"

#include "globals/state.h"
#include "globals/hardware.h"

#include "wish.h"


void wish_setup() {
    LCD.backlight(); // todo remove

    BUZZER.initSong(&UNDERTALE_ONCE_UPON_A_TIME_SONG, 1);

    // Calculate number of wishes stored in the PROGMEM:
    const uint8_t wishes_count = sizeof(WISHES) / sizeof(WISHES[0]);

    // Read index of the current wish:
    uint8_t wish_index = EEPROM.read(WISH_INDEX_EEPROM_ADDRESS);

    // Reset index of the current wish to 0 if it is out of range:
    if (wish_index >= wishes_count) {
        wish_index = 0;
//        Serial.println(F("warn: reset wish index to 0 as the stored one is out of range"));
    }
//    Serial.println("debug: wish with index " + String(wish_index) + " will be displayed");

    // Read current wish and put it into a buffer:
    const char *wish = (const char *) (pgm_read_ptr(&WISHES[wish_index]));
    char buffer[WISH_BUFSIZE];
    strcpy_P(buffer, wish);

    // Initialize wish scrolling on the LCD:
    LCD.initScrolling(buffer, WISH_DISPLAY_COUNT);

    // Update stored wish index for the next wish to be displayed next time:
    EEPROM.write(WISH_INDEX_EEPROM_ADDRESS, wish_index + 1);

    ARDUINO_STATE = ArduinoState::WISH_LOOP;
}

void wish_loop() {
    BUZZER.handle();
    LCD.handleScrolling(LCD_SCROLLING_FIRST_FRAME_DURATION, LCD_SCROLLING_FRAME_DURATION);
    if (!LCD.isScrolling()) {
        if (BUZZER.getState() == BuzzerState::PLAYING_SONG) {
            BUZZER.finishSong();
        } else {
            ARDUINO_STATE = ArduinoState::GOODBYE_SETUP;
        }
    }
}