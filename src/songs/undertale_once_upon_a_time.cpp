/*
    This file contains Undertale: Once upon a Time song (4/4) (edited and shortened).
    Source: https://musescore.com/user/5771981/scores/1407296.
*/

#include "avr/pgmspace.h"

#include "Song.h"

#include "undertale_once_upon_a_time.h"

const Note UNDERTALE_ONCE_UPON_A_TIME_SONG_NOTES[] PROGMEM = {
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
        {TONE_F5,   NoteDuration::WHOLE},

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

        // Bar 17:
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_E4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 18:
        {TONE_C4,   NoteDuration::HALF},
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_A4,   NoteDuration::QUARTER},

        // Bar 19:
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_E4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 20:
        {TONE_G4,   NoteDuration::HALF},
        {TONE_E5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::SIXTEENTH},
        {TONE_D5,   NoteDuration::SIXTEENTH},

        // Bar 21:
        {TONE_C5,   NoteDuration::WHOLE},

        // Bar 22:
        {TONE_E4,   NoteDuration::HALF},
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_A4,   NoteDuration::QUARTER},

        // Bar 23:
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_A4,   NoteDuration::QUARTER},

        // Bar 24:
        {TONE_E4,   NoteDuration::HALF},
        {TONE_G4,   NoteDuration::HALF},

        // Bar 25:
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_E4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 26:
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 27:
        {TONE_B3,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 28:
        {TONE_Bb3,  NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_Bb4,  NoteDuration::QUARTER},

        // Bar 29:
        {TONE_A4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_C4,   NoteDuration::QUARTER},

        // Bar 30:
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 31:
        {TONE_B3,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 32:
        {TONE_Bb3,  NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_Bb4,  NoteDuration::QUARTER},

        // Bar 33:
        {TONE_A4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_C4,   NoteDuration::QUARTER},

        // Bar 34:
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 35:
        {TONE_B3,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 36:
        {TONE_Bb3,  NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_Bb4,  NoteDuration::QUARTER},

        // Bar 37:
        {TONE_A4,   NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_C4,   NoteDuration::QUARTER},

        // Bar 38:
        {TONE_REST, NoteDuration::WHOLE},

};

const Song UNDERTALE_ONCE_UPON_A_TIME_SONG = Song(
        UNDERTALE_ONCE_UPON_A_TIME_SONG_NOTES,
        sizeof(UNDERTALE_ONCE_UPON_A_TIME_SONG_NOTES) / sizeof(UNDERTALE_ONCE_UPON_A_TIME_SONG_NOTES[0]),
        50,
        130,
        4
);

