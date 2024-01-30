#include "EEPROM.h"

#include "settings.h"
#include "globals/state.h"
#include "globals/hardware.h"
#include "songs/undertale_once_upon_a_time.h"

#include "wish.h"

void wish_setup() {
    LCD.backlight(); // todo remove

    // initialize wish song
    BUZZER.initSong(WISH_SONG, WISH_SONG_REPEAT);

    // read index of the current wish:
    uint8_t wish_index = EEPROM.read(WISH_INDEX_EEPROM_ADDRESS);
//    Serial.println("dbg: number of wishes = " + String(WISHES_LEN));

    // reset index of the current wish to 0 if it is out of range (just in case):
    if (wish_index > WISHES_COUNT - 1) {
        wish_index = 0;
//        Serial.println(F("dbg: reset wish index to 0 as the stored one is out of range"));
    }
//    Serial.println("dbg: wish with index " + String(wish_index) + " will be displayed");

    // read current wish and put it into a buffer:
    const char *wish = (const char *) (pgm_read_ptr(&WISHES[wish_index]));
    char buffer[WISH_TEXT_BUFSIZE];
    strcpy_P(buffer, wish);

    // initialize wish scrolling on the LCD:
    LCD.initScrolling(buffer, WISH_SCROLL_REPEAT);

    // update stored wish index to display the next wish next time:
    uint8_t next_wish_index;
    if (wish_index == WISHES_COUNT - 1) { // if current wish was the last one
        next_wish_index = 0;
    } else {
        next_wish_index = wish_index + 1;
    }
    EEPROM.write(WISH_INDEX_EEPROM_ADDRESS, next_wish_index);

    ARDUINO_STATE = ArduinoState::WISH_LOOP;
}

void wish_loop() {
    BUZZER.handle();
    LCD.handleScrolling(LCD_SCROLLING_FIRST_FRAME_DURATION, LCD_SCROLLING_FRAME_DURATION);
    if (!LCD.isScrolling() && BUZZER.getState() == BuzzerState::STANDBY) {
        ARDUINO_STATE = ArduinoState::GOODBYE_SETUP;
    }
}