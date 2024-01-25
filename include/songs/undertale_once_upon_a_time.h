/*
    This file contains Undertale: Once upon a Time song (4/4) (edited and shortened).
    Source: https://musescore.com/user/5771981/scores/1407296.
*/


#ifndef EVERLASTING_BIRTHDAY_CARD_UNDERTALE_H
#define EVERLASTING_BIRTHDAY_CARD_UNDERTALE_H

#include "stdint.h"

#include "../../lib/Note/Note.h"
#include "../../lib/Song/Song.h"

// Undertale - Once Upon a Time (4/4).
// https://musescore.com/user/5771981/scores/1407296

const Note UNDERTALE_ONCE_UPON_A_TIME_SONG_NOTES[] = {
        // Bar 1:
        {TONE_C5,   NoteDuration::HALF},
        {TONE_C6,   NoteDuration::HALF},

        // Bar2:
        {TONE_G5,   NoteDuration::WHOLE},

        // Bar 3:
        {TONE_F5,   NoteDuration::HALF},
        {TONE_C6,   NoteDuration::HALF},

        // Bar 4:
        {TONE_C5,   NoteDuration::WHOLE},

        // Bar 5:
        {TONE_C5,   NoteDuration::HALF},
        {TONE_F5,   NoteDuration::HALF},

        // Bar 6:
        {TONE_C6,   NoteDuration::HALF},
        {TONE_D6,   NoteDuration::HALF},

        // Bar 7:
        {TONE_C6,   NoteDuration::HALF},
        {TONE_G5,   NoteDuration::HALF},

        // Bar 8:
        {TONE_F5,   NoteDuration::HALF},
        {TONE_REST, NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Bb3,  NoteDuration::SIXTEENTH},
        {TONE_B3,   NoteDuration::SIXTEENTH},

        // Some changes applied ... todo

        // Bar 9:
        {TONE_C4,   NoteDuration::HALF},
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_A4,   NoteDuration::QUARTER},

        // Bar 10:
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_E4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 11:
        {TONE_G4,   NoteDuration::HALF},
        {TONE_E5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::SIXTEENTH},
        {TONE_D5,   NoteDuration::SIXTEENTH},

        // Bar 12:
        {TONE_C5,   NoteDuration::WHOLE},

        // Bar 13:
        {TONE_E4,   NoteDuration::HALF},
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_A4,   NoteDuration::QUARTER},

        // Bar 14:
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_A4,   NoteDuration::QUARTER},

        // Bar 16:
        {TONE_E4,   NoteDuration::HALF},
        {TONE_G4,   NoteDuration::HALF},

        // Bar 16:
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_E4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
};

/// Gap between notes in ms (to avoid legato).
const uint8_t UNDERTALE_ONCE_UPON_A_TIME_SONG_NOTE_GAP = 20;

/// BPM rate of the song.
const uint8_t UNDERTALE_ONCE_UPON_A_TIME_BPM = 100;

/// Song with its notes and other settings.
const Song UNDERTALE_ONCE_UPON_A_TIME_SONG = Song(
        UNDERTALE_ONCE_UPON_A_TIME_SONG_NOTES,
        sizeof(UNDERTALE_ONCE_UPON_A_TIME_SONG_NOTES) / sizeof(UNDERTALE_ONCE_UPON_A_TIME_SONG_NOTES[0]),
        UNDERTALE_ONCE_UPON_A_TIME_SONG_NOTE_GAP,
        UNDERTALE_ONCE_UPON_A_TIME_BPM
);

#endif //EVERLASTING_BIRTHDAY_CARD_UNDERTALE_H
