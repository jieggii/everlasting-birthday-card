#ifndef EVERLASTING_BIRTHDAY_CARD_SETTINGS_H

#include "Arduino.h"

#include "../lib/Song/Song.h"
#include "../lib/Note/Note.h"

// Celebrate countdown settings:
/// Countdown ticks count:
const unsigned short CELEBRATE_COUNTDOWN_TICK_COUNT = 10;

/// Tone of the countdown tick.
const unsigned short CELEBRATE_COUNTDOWN_TICK_TONE = 392;

/// Duration of a countdown tick.
const unsigned short CELEBRATE_COUNTDOWN_TICK_DURATION = 200;

/// Time interval between countdown ticks (ms)
const unsigned short CELEBRATE_COUNTDOWN_TICK_INTERVAL = 1000;


// Sleep countdown settings:
/// Countdown ticks count:
const unsigned short SLEEP_COUNTDOWN_TICK_COUNT = 10;

/// Tone of the countdown tick.
const unsigned short SLEEP_COUNTDOWN_TICK_TONE = 392;

/// Duration of a countdown tick.
const unsigned short SLEEP_COUNTDOWN_TICK_DURATION = 200;

/// Time interval between countdown ticks (ms)
const unsigned short SLEEP_COUNTDOWN_TICK_INTERVAL = 1000;


// Song settings:
/// BPM of the song.
const unsigned short SONG_BPM = 90;

// Gap between notes in ms (to avoid legato).
const unsigned short SONG_NOTE_GAP = 10;

/// Array of song notes
Note SONG_NOTES[] = { // this is a birthday song in Cmaj, measure is 3/4.
        // Bar 1:
        Note(TONE_G3, NOTE_DURATION_EIGHTH),
        Note(TONE_G3, NOTE_DURATION_EIGHTH),
        Note(TONE_A3, NOTE_DURATION_QUARTER),
        Note(TONE_G3, NOTE_DURATION_QUARTER),

        // Bar 2:
        Note(TONE_C4, NOTE_DURATION_QUARTER),
        Note(TONE_B3, NOTE_DURATION_HALF),

        // Bar 3:
        Note(TONE_G3, NOTE_DURATION_EIGHTH),
        Note(TONE_G3, NOTE_DURATION_EIGHTH),
        Note(TONE_A3, NOTE_DURATION_QUARTER),
        Note(TONE_G3, NOTE_DURATION_QUARTER),

        // Bar 4:
        Note(TONE_D4, NOTE_DURATION_QUARTER),
        Note(TONE_C4, NOTE_DURATION_HALF),

        // Bar 5:
        Note(TONE_G3, NOTE_DURATION_EIGHTH),
        Note(TONE_G3, NOTE_DURATION_EIGHTH),
        Note(TONE_G4, NOTE_DURATION_QUARTER),
        Note(TONE_E4, NOTE_DURATION_QUARTER),

        // Bar 6:
        Note(TONE_C4, NOTE_DURATION_QUARTER),
        Note(TONE_B3, NOTE_DURATION_QUARTER),
        Note(TONE_A3, NOTE_DURATION_QUARTER),

        // Bar 7:
        Note(TONE_F4, NOTE_DURATION_EIGHTH),
        Note(TONE_F4, NOTE_DURATION_EIGHTH),
        Note(TONE_E4, NOTE_DURATION_QUARTER),
        Note(TONE_C4, NOTE_DURATION_QUARTER),

        // Bar 8:
        Note(TONE_D4, NOTE_DURATION_QUARTER),
        Note(TONE_C4, NOTE_DURATION_HALF),
};

/// Number of notes in the song.
const unsigned short SONG_NOTES_COUNT = 25;

/// Song with its notes and other settings.
Song SONG = Song(
        SONG_BPM,
        SONG_NOTES,
        SONG_NOTES_COUNT,
        SONG_NOTE_GAP
);


// Microphone settings:
/// Microphone trigger treshold from 0 to 1023.
const unsigned short MICROPHONE_TRIGGER_TRESHOLD = 1010;

// Required streak of treshold readings for microphone to be triggerred.
const unsigned short MICROPHONE_TRIGGER_STREAK = 5;

// Wishes settings:
/// Array of wishes will be displayed in order year by year.
String WISH_LIST[] = {
        "Ti bolshaya molodec v etom godu, tak derjat umnichka. Jelayu uspehov i vsego samogo nailu4shego v etom godu",
//        "I am really proud of you because you've improved your english this year. I'm sure that you've achieved a lot of other goals too!",
//        "Pivet! S dem rojdenia, ti virosla za etot god kak 4elovek vo vseh smislah etogo slova. Tak derjat!",
//        "pivet!!!",
};

/// Amount of wishes in WISH_LIST.
//const uint8_t WISH_COUNT = 3;

/// Wish caption (will be displayed under all wishes being displayed).
String WISH_CAPTION = "elle4ka, c dr!!!";

/// Index of current wish will be reset to 0 if WISH_INDEX_RESET is true.
const bool WISH_INDEX_RESET = false;

/// Address of Arduino EEPROM memory to store index of the current wish.
const short WISH_INDEX_EEPROM_ADDRESS = 0;

/// Duration of the wish state (in ms):
//const unsigned long WISH_DURATION = 60UL * 5 * 1000;
const unsigned long WISH_DURATION = 50UL * 1000 * 1;

/// Duration of the first frame of wish in the lcd screen.
const unsigned short WISH_DISPLAY_FIRST_FRAME_DURATION = 2500;

/// Duration of all frames of wish except the first frame in the lcd screen.
const unsigned short WISH_DISPLAY_FRAME_DURATION = 500;


// Birthday date settings:
/// Birthday year.
const unsigned short BIRTH_YEAR = 2005;

/// Birthday month.
const unsigned short BIRTH_MONTH = 1;

/// Birthday date.
const unsigned short BIRTH_DAY = 1;

/// Birthday hour.
const unsigned short BIRTH_HOUR = 0;

/// Birthday minutes.
const unsigned short BIRTH_MINUTE = 15;

/// Birthday seconds.
const unsigned short BIRTH_SECOND = 0; // does not make much sense, but useful when debugging

#define EVERLASTING_BIRTHDAY_CARD_SETTINGS_H

#endif //EVERLASTING_BIRTHDAY_CARD_SETTINGS_H
