/*
    This file contains Undertale: Your Best Friend (4/4).
    Source: https://musescore.com/user/3726186/scores/1864621
*/

#include "avr/pgmspace.h"

#include "Song.h"

#include "undertale_your_best_friend.h"

const Note UNDERTALE_YOUR_BEST_FRIEND_NOTES[] PROGMEM = {
        // Bar 1:
        {TONE_Ab4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Eb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 2:
        {TONE_Ab4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Eb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},


        // Bar 3:
        {TONE_Ab4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Eb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 4:
        {TONE_Ab4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Eb4,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C5,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 5:
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Db6,  NoteDuration::EIGHTH},
        {TONE_Eb6,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 6:
        {TONE_Db6,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Db6,  NoteDuration::EIGHTH},
        {TONE_Eb6,  NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},

        // Bar 7:
        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Db6,  NoteDuration::EIGHTH},

        {TONE_Eb6,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Ab6,  NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 8:
        {TONE_F6,   NoteDuration::QUARTER},
        {TONE_F6,   NoteDuration::EIGHTH},
        {TONE_F6,   NoteDuration::SIXTEENTH},
        {TONE_Eb6,  NoteDuration::THIRTY_SECOND},
        {TONE_F6,   NoteDuration::THIRTY_SECOND},
        {TONE_Eb6,  NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},

        // Bar 9:
        {TONE_C6,   NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C6,   NoteDuration::EIGHTH},
        {TONE_Db6,  NoteDuration::EIGHTH},
        {TONE_Eb6,  NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_C6,   NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 10:
        {TONE_Db6,  NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Db6,  NoteDuration::EIGHTH},
        {TONE_Eb6,  NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_G5,   NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 11:
        {TONE_Db6,  NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_Db6,  NoteDuration::EIGHTH},
        {TONE_Bb5,  NoteDuration::EIGHTH},
        {TONE_Eb6,  NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::EIGHTH},

        {TONE_G5,   NoteDuration::EIGHTH},

        {TONE_REST, NoteDuration::EIGHTH},

        // Bar 12:
        {TONE_Ab5,  NoteDuration::HALF},
        {TONE_Ab6,  NoteDuration::HALF},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},

        // Bar 13:
        {TONE_REST, NoteDuration::WHOLE},


};

const Song UNDERTALE_YOUR_BEST_FRIEND_SONG = Song(
        UNDERTALE_YOUR_BEST_FRIEND_NOTES,
        sizeof(UNDERTALE_YOUR_BEST_FRIEND_NOTES) / sizeof(UNDERTALE_YOUR_BEST_FRIEND_NOTES[0]),
        50,
        125,
        4
);
