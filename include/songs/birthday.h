/*
    This file contains Happy Birthday song in Cmaj (3/4).
    Source: https://musescore.com/user/173585/scores/166951.
*/

#ifndef EVERLASTING_BIRTHDAY_CARD_BIRTHDAY_H
#define EVERLASTING_BIRTHDAY_CARD_BIRTHDAY_H

#include "../../lib/Song/Song.h"


const Note BIRTHDAY_SONG_NOTES[] PROGMEM = {
        // Bar 1:
        {TONE_G3, NoteDuration::EIGHTH},
        {TONE_G3, NoteDuration::EIGHTH},
        {TONE_A3, NoteDuration::QUARTER},
        {TONE_G3, NoteDuration::QUARTER},

        // Bar 2:
        {TONE_C4, NoteDuration::QUARTER},
        {TONE_B3, NoteDuration::HALF},

        // Bar 3:
        {TONE_G3, NoteDuration::EIGHTH},
        {TONE_G3, NoteDuration::EIGHTH},
        {TONE_A3, NoteDuration::QUARTER},
        {TONE_G3, NoteDuration::QUARTER},

        // Bar 4:
        {TONE_D4, NoteDuration::QUARTER},
        {TONE_C4, NoteDuration::HALF},

        // Bar 5:
        {TONE_G3, NoteDuration::EIGHTH},
        {TONE_G3, NoteDuration::EIGHTH},
        {TONE_G4, NoteDuration::QUARTER},
        {TONE_E4, NoteDuration::QUARTER},

        // Bar 6:
        {TONE_C4, NoteDuration::QUARTER},
        {TONE_B3, NoteDuration::QUARTER},
        {TONE_A3, NoteDuration::QUARTER},

        // Bar 7:
        {TONE_F4, NoteDuration::EIGHTH},
        {TONE_F4, NoteDuration::EIGHTH},
        {TONE_E4, NoteDuration::QUARTER},
        {TONE_C4, NoteDuration::QUARTER},

        // Bar 8:
        {TONE_D4, NoteDuration::QUARTER},
        {TONE_C4, NoteDuration::HALF},
};

/// Song with its notes and other settings.
const Song BIRTHDAY_SONG = Song(
        BIRTHDAY_SONG_NOTES,
        sizeof(BIRTHDAY_SONG_NOTES) / sizeof(BIRTHDAY_SONG_NOTES[0]),
        30,
        75
);


#endif //EVERLASTING_BIRTHDAY_CARD_BIRTHDAY_H
