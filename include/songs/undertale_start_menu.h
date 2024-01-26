#ifndef EVERLASTING_BIRTHDAY_CARD_UNDERTALE_START_MENU_H
#define EVERLASTING_BIRTHDAY_CARD_UNDERTALE_START_MENU_H

/*
    This file contains Undertale: Start menu (4/4).
    Source: https://musescore.com/user/3726186/scores/1864606
*/


#ifndef EVERLASTING_BIRTHDAY_CARD_UNDERTALE_H
#define EVERLASTING_BIRTHDAY_CARD_UNDERTALE_H

#include "stdint.h"

#include "avr/pgmspace.h"
#include "../../lib/Note/Note.h"
#include "../../lib/Song/Song.h"


const Note UNDERTALE_START_MENU_SONG_NOTES[] = {
        // Bar 1:
        {TONE_G3,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_D4,   NoteDuration::EIGHTH},

        // Bar 2:
        {TONE_REST, NoteDuration::WHOLE},

        // Bar 3:
        {TONE_C4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_G3,   NoteDuration::EIGHTH},

        // Bar 4:
        {TONE_REST, NoteDuration::WHOLE},

        // Bar 5:
        {TONE_G3,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},
        {TONE_C4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_G4,   NoteDuration::EIGHTH},

        // Bar 6:
        {TONE_REST, NoteDuration::HALF},
        {TONE_A4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},

        // Bar 7:
        {TONE_G3,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},
        {TONE_D4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_C4,   NoteDuration::EIGHTH},

        // Bar 8:
        {TONE_REST, NoteDuration::WHOLE},

        // Bar 9:
        {TONE_G3,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_D4,   NoteDuration::EIGHTH},

        // Bar 10:
        {TONE_REST, NoteDuration::WHOLE},

        // Bar 11:
        {TONE_C4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},
        {TONE_G4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_G3,   NoteDuration::EIGHTH},

        // Bar 12:
        {TONE_REST, NoteDuration::WHOLE},

        // Bar 13:
        {TONE_G3,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},
        {TONE_C4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_G4,   NoteDuration::EIGHTH},

        // Bar 14:
        {TONE_REST, NoteDuration::HALF},
        {TONE_A4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},

        // Bar 15:
        {TONE_G3,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::QUARTER},
        {TONE_D4,   NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_REST, NoteDuration::EIGHTH},
        {TONE_C4,   NoteDuration::EIGHTH},

        // Bar 16:
        {TONE_REST, NoteDuration::WHOLE}
};

/// Gap between notes in ms (to avoid legato).
const uint8_t UNDERTALE_START_MENU_SONG_NOTE_GAP = 20;

/// BPM rate of the song.
const uint8_t UNDERTALE_START_MENU_SONG_BPM = 181;

/// Song with its notes and other settings.
const Song UNDERTALE_START_MENU_SONG = Song(
        UNDERTALE_START_MENU_SONG_NOTES,
        sizeof(UNDERTALE_START_MENU_SONG_NOTES) / sizeof(UNDERTALE_START_MENU_SONG_NOTES[0]),
        UNDERTALE_START_MENU_SONG_NOTE_GAP,
        UNDERTALE_START_MENU_SONG_BPM
);

#endif //EVERLASTING_BIRTHDAY_CARD_UNDERTALE_H
#endif //EVERLASTING_BIRTHDAY_CARD_UNDERTALE_START_MENU_H
