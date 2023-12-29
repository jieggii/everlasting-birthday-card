#ifndef EVERLASTING_BIRTHDAY_CARD_SETTINGS_H

#include "Arduino.h"

#include "../lib/Song/Song.h"
#include "../lib/Note/Note.h"

// Celebrate countdown settings:
/// Countdown ticks count:
const unsigned short CELEBRATE_COUNTDOWN_TICK_COUNT = 30;

/// Tone of the countdown tick.
const unsigned short CELEBRATE_COUNTDOWN_TICK_TONE = 196 * 2;

/// Duration of a countdown tick.
const unsigned short CELEBRATE_COUNTDOWN_TICK_DURATION = 200;

/// Time interval between countdown ticks (ms)
const unsigned short CELEBRATE_COUNTDOWN_TICK_INTERVAL = 1000;


// Song settings:
/// BPM of the song.
const unsigned short SONG_BPM = 90;

// Gap between notes in ms (to avoid legato).
const unsigned short SONG_NOTE_GAP = 10;

/// Number of notes in the song.
const unsigned short SONG_NOTES_COUNT = 25;

/// Array of song notes
Note SONG_NOTES[] = {
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

Song SONG = Song(SONG_BPM, SONG_NOTES, SONG_NOTES_COUNT, SONG_NOTE_GAP);


// Microphone settings:
/// Microphone trigger treshold from 0 to 1023.
const unsigned short MICROPHONE_TRIGGER_TRESHOLD = 600;

// Required streak of treshold readings to trigger.
const unsigned short MICROPHONE_TRIGGER_STREAK = 5;

// Wishes settings:
/// Array of wishes will be displayed in order year by year:
String WISHES[] = {"wish 1", "wish 2"};

/// Wish caption (will be displayed under all wishes being displayed):
String WISH_CAPTION = "<3 uraa s dr!!!";

/// Duration of the wish state (in ms):
//const unsigned long WISH_DURATION = 60UL * 5 * 1000;
const unsigned long WISH_DURATION = 5000;

/// Duration of the first frame of wish in the lcd screen.
const unsigned short WISH_DISPLAY_FIRST_FRAME_DURATION = 3 * 1000;

/// Duration of all frames of wish except the first frame in the lcd screen.
const unsigned short WISH_DISPLAY_FRAME_DURATION = 500;


// Sleep countdown settings:
/// Countdown ticks count:
const unsigned short SLEEP_COUNTDOWN_TICK_COUNT = 10;

/// Tone of the countdown tick.
const unsigned short SLEEP_COUNTDOWN_TICK_TONE = 196 * 2;

/// Duration of a countdown tick.
const unsigned short SLEEP_COUNTDOWN_TICK_DURATION = 200;

/// Time interval between countdown ticks (ms)
const unsigned short SLEEP_COUNTDOWN_TICK_INTERVAL = 1000;

// Other settings:
//const unsigned short BORN_YEAR = 2005;

#define EVERLASTING_BIRTHDAY_CARD_SETTINGS_H

#endif //EVERLASTING_BIRTHDAY_CARD_SETTINGS_H
