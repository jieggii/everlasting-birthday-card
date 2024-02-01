/*
    This file contains Undertale: Tem shop (4/4).
    Source: https://musescore.com/user/5507221/scores/3746261
*/

#include "avr/pgmspace.h"

#include "Song.h"

#include "undertale_tem_shop.h"

const Note UNDERTALE_TEM_SHOP_SONG_NOTES[] PROGMEM = {
        // Bar 1:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Db4,  NoteDuration::SIXTEENTH},
        {TONE_Eb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},

        // Bar 2:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_F4,   NoteDuration::EIGHTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_Ab4,  NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 3:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Db4,  NoteDuration::SIXTEENTH},
        {TONE_Eb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},

        // Bar 4:
        {TONE_B4,   NoteDuration::SIXTEENTH},
        {TONE_Bb4,  NoteDuration::SIXTEENTH},
        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_F4,   NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Eb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Repeat bar 1 - 4:
        // Bar 1:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Db4,  NoteDuration::SIXTEENTH},
        {TONE_Eb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},

        // Bar 2:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_F4,   NoteDuration::EIGHTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_Ab4,  NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 3:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Db4,  NoteDuration::SIXTEENTH},
        {TONE_Eb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},

        // Bar 4:
        {TONE_B4,   NoteDuration::SIXTEENTH},
        {TONE_Bb4,  NoteDuration::SIXTEENTH},
        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_F4,   NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Eb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 5:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::SIXTEENTH},
        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::SIXTEENTH},
        {TONE_Db5,  NoteDuration::SIXTEENTH},
        {TONE_Eb5,  NoteDuration::SIXTEENTH},

        // Bar 6:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_Bb4,  NoteDuration::SIXTEENTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::SIXTEENTH},
        {TONE_Ab4,  NoteDuration::EIGHTH},

        // Bar 7:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::SIXTEENTH},
        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::SIXTEENTH},
        {TONE_Db5,  NoteDuration::SIXTEENTH},
        {TONE_Eb5,  NoteDuration::SIXTEENTH},

        // Bar 8:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_Ab5,  NoteDuration::SIXTEENTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_F5,   NoteDuration::EIGHTH},

        // Repeat bars 5 - 8:
// Bar 5:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::SIXTEENTH},
        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::SIXTEENTH},
        {TONE_Db5,  NoteDuration::SIXTEENTH},
        {TONE_Eb5,  NoteDuration::SIXTEENTH},

        // Bar 6:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_Bb4,  NoteDuration::SIXTEENTH},
        {TONE_B4,   NoteDuration::EIGHTH},
        {TONE_Bb4,  NoteDuration::SIXTEENTH},
        {TONE_Ab4,  NoteDuration::EIGHTH},

        // Bar 7:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_Gb5,  NoteDuration::SIXTEENTH},
        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::SIXTEENTH},
        {TONE_Db5,  NoteDuration::SIXTEENTH},
        {TONE_Eb5,  NoteDuration::SIXTEENTH},

        // Bar 8:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_F5,   NoteDuration::EIGHTH},
        {TONE_Ab5,  NoteDuration::SIXTEENTH},
        {TONE_Gb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_F5,   NoteDuration::EIGHTH},

        // Repeat bars 1-4:
        // Bar 1:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Db4,  NoteDuration::SIXTEENTH},
        {TONE_Eb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},

        // Bar 2:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Eb5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_F4,   NoteDuration::EIGHTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_Ab4,  NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 3:
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_Db5,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Bb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::EIGHTH},
        {TONE_Db4,  NoteDuration::SIXTEENTH},
        {TONE_Eb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},

        // Bar 4:
        {TONE_B4,   NoteDuration::SIXTEENTH},
        {TONE_Bb4,  NoteDuration::SIXTEENTH},
        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Ab4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_F4,   NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::SIXTEENTH},

        {TONE_Eb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_Gb4,  NoteDuration::SIXTEENTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // The las bar:
        {TONE_REST, NoteDuration::WHOLE}
};

/// Song with its notes and other settings.
const Song UNDERTALE_TEM_SHOP_SONG = Song(
        UNDERTALE_TEM_SHOP_SONG_NOTES,
        sizeof(UNDERTALE_TEM_SHOP_SONG_NOTES) / sizeof(UNDERTALE_TEM_SHOP_SONG_NOTES[0]),
        20,
        96,
        4
);

