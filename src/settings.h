#ifndef EVERLASTING_BIRTHDAY_CARD_SETTINGS_H
#define EVERLASTING_BIRTHDAY_CARD_SETTINGS_H

#include "avr/pgmspace.h"

#include "Song.h"
#include "../lib/BirthDate/BirthDate.h"

extern const Song *HOME_SONGS[];
extern const uint8_t HOME_SONGS_COUNT;

extern const uint8_t COUNTDOWN_TICKS_COUNT;
extern const unsigned short COUNTDOWN_TICK_TONE;
extern const unsigned short COUNTDOWN_TICK_DURATION;
extern const unsigned short COUNTDOWN_TICK_INTERVAL;

extern const Song *CELEBRATE_SONG;
extern const uint8_t CELEBRATE_SONG_REPEAT;
extern const char CELEBRATE_TEXT[] PROGMEM;

extern const unsigned short MICROPHONE_TRIGGER_TRESHOLD;
extern const unsigned short MICROPHONE_TRIGGER_STREAK;

extern const Song *WISH_SONG;
extern const uint8_t WISH_SONG_REPEAT;
extern const uint8_t WISH_SCROLL_REPEAT;
extern const char *const WISHES[] PROGMEM;
extern const uint8_t WISHES_COUNT;

extern const char GOODBYE_TEXT[] PROGMEM;

extern const BirthDate BIRTH_DATE;

extern const unsigned short LCD_SCROLLING_FIRST_FRAME_DURATION;
extern const unsigned short LCD_SCROLLING_FRAME_DURATION;

extern const uint8_t WISH_INDEX_EEPROM_ADDRESS;
extern const bool WISH_INDEX_RESET;
extern const uint8_t WISH_INDEX_RESET_TO;
extern const bool RTC_RESET;

/*
    Note about buffer sizes:
    The reason this section is present and buffer sizes are not calculated automatically
    is my lack of knowledge. I could not manage to make it work for 3-4 days, so I've decided
    to stick to this at this point.

    Defining buffer sizes as constants that are equal to `sizeof(EXAMPLE_PGMEM_TEXT)` or `strlen_P(EXAMPLE_PGMEM_TEXT)` + 1
    did not work *for some reason* for strings that were longer than 24 characters, despite the fact that their lengths were calculated correctly.
    I will appreciate any help with that!

    So, for now you will have to manually set buffer sizes for that will be displayed on the screen.
    The rule is simple: buffer size must be at least number of characters in a string + 1.
    For example, for string "hello" buffer size must be at least 5 + 1 = 6.
*/
#define CELEBRATE_TEXT_BUFSIZE 255
#define WISH_TEXT_BUFSIZE 255
#define GOODBYE_TEXT_BUFSIZE 255

#endif //EVERLASTING_BIRTHDAY_CARD_SETTINGS_H