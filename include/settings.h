#ifndef EVERLASTING_BIRTHDAY_CARD_SETTINGS_H

#include "drivers/Song.h"
#include "drivers/Note.h"

// Song settings:
// BPM of the song.
const unsigned short SONG_BPM = 90;

// Gap between notes in ms (to avoid legato).
const unsigned short SONG_NOTE_GAP = 10;

// Number of notes in the song.
const unsigned short SONG_NOTES_COUNT = 25;

// Array of song notes
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
// Microphone trigger treshold from 0 to 1023.
const short MICROPHONE_TRIGGER_TRESHOLD = 1023;

// Required streak of treshold readings to trigger.
const short MICROPHONE_TRIGGER_STREAK = 1;


// Countdown settings:
// Countdown ticks count:
const short COUNTDOWN_TICK_COUNT = 2;

// Tone of the countdown tick.
const short COUNTDOWN_TICK_TONE = 196 * 2;

// Duration of a countdown tick.
const short COUNTDOWN_TICK_DURATION = 100;

// Time interval between countdown ticks (ms)
const short COUNTDOWN_TICK_INTERVAL = 400;


#define EVERLASTING_BIRTHDAY_CARD_SETTINGS_H

#endif //EVERLASTING_BIRTHDAY_CARD_SETTINGS_H
