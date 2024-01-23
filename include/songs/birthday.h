#ifndef EVERLASTING_BIRTHDAY_CARD_BIRTHDAY_H
#define EVERLASTING_BIRTHDAY_CARD_BIRTHDAY_H

#include "../../lib/Song/Song.h"


const Note BIRTHDAY_SONG_NOTES[] = { // this is a happy birthday song in Cmaj, measure is 3/4.
        // Bar 1:
        {TONE_G3, NOTE_DURATION_EIGHTH},
        {TONE_G3, NOTE_DURATION_EIGHTH},
        {TONE_A3, NOTE_DURATION_QUARTER},
        {TONE_G3, NOTE_DURATION_QUARTER},

        // Bar 2:
        {TONE_C4, NOTE_DURATION_QUARTER},
        {TONE_B3, NOTE_DURATION_HALF},

        // Bar 3:
        {TONE_G3, NOTE_DURATION_EIGHTH},
        {TONE_G3, NOTE_DURATION_EIGHTH},
        {TONE_A3, NOTE_DURATION_QUARTER},
        {TONE_G3, NOTE_DURATION_QUARTER},

        // Bar 4:
        {TONE_D4, NOTE_DURATION_QUARTER},
        {TONE_C4, NOTE_DURATION_HALF},

        // Bar 5:
        {TONE_G3, NOTE_DURATION_EIGHTH},
        {TONE_G3, NOTE_DURATION_EIGHTH},
        {TONE_G4, NOTE_DURATION_QUARTER},
        {TONE_E4, NOTE_DURATION_QUARTER},

        // Bar 6:
        {TONE_C4, NOTE_DURATION_QUARTER},
        {TONE_B3, NOTE_DURATION_QUARTER},
        {TONE_A3, NOTE_DURATION_QUARTER},

        // Bar 7:
        {TONE_F4, NOTE_DURATION_EIGHTH},
        {TONE_F4, NOTE_DURATION_EIGHTH},
        {TONE_E4, NOTE_DURATION_QUARTER},
        {TONE_C4, NOTE_DURATION_QUARTER},

        // Bar 8:
        {TONE_D4, NOTE_DURATION_QUARTER},
        {TONE_C4, NOTE_DURATION_HALF},
};

/// Gap between notes in ms (to avoid legato).
const uint8_t BIRTHDAY_SONG_NOTE_GAP = 10;

/// BPM rate of the song.
const uint8_t BIRTHDAY_SONG_BPM = 90;

/// Song with its notes and other settings.
const Song BIRTHDAY_SONG = Song(
        BIRTHDAY_SONG_NOTES,
        sizeof(BIRTHDAY_SONG_NOTES) / sizeof(BIRTHDAY_SONG_NOTES[0]),
        BIRTHDAY_SONG_NOTE_GAP,
        BIRTHDAY_SONG_BPM
);


#endif //EVERLASTING_BIRTHDAY_CARD_BIRTHDAY_H
