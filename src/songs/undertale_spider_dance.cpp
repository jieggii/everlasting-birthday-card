/*
    This file contains Undertale: Spider Dance.
    Source: https://musescore.com/user/25939551/scores/4793799.
*/

#include "avr/pgmspace.h"

#include "Song.h"

#include "undertale_spider_dance.h"

const Note UNDERTALE_SPIDER_DANCE_SONG_NOTES[] PROGMEM = {
        // Bar 1:
        {TONE_F5,   NoteDuration::QUARTER},
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_Ab4,  NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 2:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_Ab4,  NoteDuration::EIGHTH},
        {TONE_E4,   NoteDuration::EIGHTH},
        {TONE_F4,   NoteDuration::EIGHTH},

        // Bar 3:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_Ab4,  NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_E4,   NoteDuration::EIGHTH},
        {TONE_F4,   NoteDuration::EIGHTH},

        // Bar 4:
        {TONE_Ab4,  NoteDuration::EIGHTH},
        {TONE_F4,   NoteDuration::EIGHTH},
        {TONE_E4,   NoteDuration::EIGHTH},
        {TONE_F5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_C5,   NoteDuration::SIXTEENTH},
        {TONE_Bb4,  NoteDuration::SIXTEENTH},
        {TONE_Ab4,  NoteDuration::EIGHTH},

        // Bar 5:
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_Db4,  NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_Db4,  NoteDuration::QUARTER},

        // Bar 6:
        {TONE_Ab4,  NoteDuration::QUARTER},
        {TONE_Db4,  NoteDuration::QUARTER},
        {TONE_Bb4,  NoteDuration::HALF},

        // Bar 7:
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_Bb4,  NoteDuration::QUARTER},
        {TONE_F5,   NoteDuration::QUARTER},
        {TONE_C5,   NoteDuration::QUARTER},

        // Bar 8:
        {TONE_E5,   NoteDuration::QUARTER},
        {TONE_Db5,  NoteDuration::QUARTER},
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::QUARTER},

        // Bar 9:
        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        // Bar 10:
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_B5,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_B5,   NoteDuration::EIGHTH},

        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_G5,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},

        // Bar 11:
        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        {TONE_G5,   NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        // Bar 12:
        {TONE_Ab5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_Db6,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Db6,  NoteDuration::EIGHTH},

        // Bar 13:
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Ab5,  NoteDuration::EIGHTH},
        {TONE_G5,   NoteDuration::EIGHTH},
        {TONE_Ab5,  NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_Ab5,  NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},

        // Bar 14:
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Db6,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},

        // Bar 15:
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_Bb4,  NoteDuration::QUARTER},
        {TONE_F5,   NoteDuration::QUARTER},
        {TONE_C5,   NoteDuration::QUARTER},

        // Bar 16:
        {TONE_E5,   NoteDuration::QUARTER},
        {TONE_Db5,  NoteDuration::QUARTER},
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::QUARTER},

        // Repeat the whole song:

        // Bar 1:
        {TONE_F5,   NoteDuration::QUARTER},
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_Ab4,  NoteDuration::QUARTER},
        {TONE_F4,   NoteDuration::QUARTER},

        // Bar 2:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_Ab4,  NoteDuration::EIGHTH},
        {TONE_E4,   NoteDuration::EIGHTH},
        {TONE_F4,   NoteDuration::EIGHTH},

        // Bar 3:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_Ab4,  NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_E4,   NoteDuration::EIGHTH},
        {TONE_F4,   NoteDuration::EIGHTH},

        // Bar 4:
        {TONE_Ab4,  NoteDuration::EIGHTH},
        {TONE_F4,   NoteDuration::EIGHTH},
        {TONE_E4,   NoteDuration::EIGHTH},
        {TONE_F5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_E5,   NoteDuration::EIGHTH},
        {TONE_C5,   NoteDuration::SIXTEENTH},
        {TONE_Bb4,  NoteDuration::SIXTEENTH},
        {TONE_Ab4,  NoteDuration::EIGHTH},

        // Bar 5:
        {TONE_F4,   NoteDuration::QUARTER},
        {TONE_Db4,  NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::QUARTER},
        {TONE_Db4,  NoteDuration::QUARTER},

        // Bar 6:
        {TONE_Ab4,  NoteDuration::QUARTER},
        {TONE_Db4,  NoteDuration::QUARTER},
        {TONE_Bb4,  NoteDuration::HALF},

        // Bar 7:
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_Bb4,  NoteDuration::QUARTER},
        {TONE_F5,   NoteDuration::QUARTER},
        {TONE_C5,   NoteDuration::QUARTER},

        // Bar 8:
        {TONE_E5,   NoteDuration::QUARTER},
        {TONE_Db5,  NoteDuration::QUARTER},
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::QUARTER},

        // Bar 9:
        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        // Bar 10:
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_B5,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_B5,   NoteDuration::EIGHTH},

        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_G5,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},

        // Bar 11:
        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        {TONE_G5,   NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        // Bar 12:
        {TONE_Ab5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_Db6,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Db6,  NoteDuration::EIGHTH},

        // Bar 13:
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Ab5,  NoteDuration::EIGHTH},
        {TONE_G5,   NoteDuration::EIGHTH},
        {TONE_Ab5,  NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_Ab5,  NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},

        // Bar 14:
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_Db6,  NoteDuration::EIGHTH},
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},

        // Bar 15:
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_Bb4,  NoteDuration::QUARTER},
        {TONE_F5,   NoteDuration::QUARTER},
        {TONE_C5,   NoteDuration::QUARTER},

        // Bar 16:
        {TONE_E5,   NoteDuration::QUARTER},
        {TONE_Db5,  NoteDuration::QUARTER},
        {TONE_C5,   NoteDuration::QUARTER},
        {TONE_REST, NoteDuration::QUARTER},

        // The last bar:
        {TONE_REST, NoteDuration::WHOLE}

};

/// Song with its notes and other settings.
const Song UNDERTALE_SPIDER_DANCE_SONG = Song(
        UNDERTALE_SPIDER_DANCE_SONG_NOTES,
        sizeof(UNDERTALE_SPIDER_DANCE_SONG_NOTES) / sizeof(UNDERTALE_SPIDER_DANCE_SONG_NOTES[0]),
        30,
        120,
        4
);
