/*
    This file contains Undertale: Fallen Down (6/8).
    Source: https://musescore.com/maxmic480/scores/1686751
*/

#include "avr/pgmspace.h"

#include "Song.h"

#include "undertale_fallen_down.h"

const Note UNDERTALE_FALLEN_DOWN_NOTES[] PROGMEM = {
        // Bar 1:
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},

        // Bar 2:
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},

        // Bar 3:
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_A4,   NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_A4,   NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},

        // Bar 4:
        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},

        // Bar 5:
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},

        // Bar 6:
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_G5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 7:
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},

        // Bar 8:
        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 9:
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},

        // Bar 10:
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},

        // Bar 11:
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_A4,   NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_A4,   NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},

        // Bar 12:
        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},

        // Bar 13 (like 5):
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},

        // Bar 14 (like 6):
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_G5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 15 (like 7):
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},

        // Bar 16:
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 17:
        {TONE_D5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},


        // Bar 18:
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 19:
        {TONE_A4,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_A4,   NoteDuration::EIGHTH},
        {TONE_G4,   NoteDuration::EIGHTH},

        // Bar 20:
        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 21:
        {TONE_D5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_A4,   NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},

        // Bar 22:
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 23:
        {TONE_Gb5,  NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_G5,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_E5,   NoteDuration::EIGHTH},

        // Bar 24:
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 25:
        {TONE_D5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_A4,   NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},

        // Bar 26:
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 27:
        {TONE_A4,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_A4,   NoteDuration::EIGHTH},
        {TONE_G5,   NoteDuration::EIGHTH},

        // Bar 28:
        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 29:
        {TONE_D5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_A4,   NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},

        // Bar 30:
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 31:
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},

        // Bar 32:
        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_D5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 33:
        {TONE_D5,   NoteDuration::HALF},
        {TONE_REST, NoteDuration::HALF},

        // Bar 34:
        {TONE_REST, NoteDuration::WHOLE}
};

const Song UNDERTALE_FALLEN_DOWN_SONG = Song(
        UNDERTALE_FALLEN_DOWN_NOTES,
        sizeof(UNDERTALE_FALLEN_DOWN_NOTES) / sizeof(UNDERTALE_FALLEN_DOWN_NOTES[0]),
        50,
        107,
        3 // 6/8 ~= 3/4
);
