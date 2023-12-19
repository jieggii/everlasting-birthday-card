#ifndef EVERLASTING_BIRTHDAY_CARD_SONG_H
#define EVERLASTING_BIRTHDAY_CARD_SONG_H

#include "Note.h"

class Song {
public:
    // Song BPM.
    unsigned short bpm;

    // Array of song notes.
    Note *notes;

    // Number of notes in the song.
    unsigned short notes_count;

    // Gap between notes in ms.
    unsigned short note_gap;

    // Duration of a half note in ms.
    unsigned int half_duration;

    // Duration of a quarter note in ms.
    unsigned int quarter_duration;

    // Duration of an eighth note in ms.
    unsigned int eighth_duration;

    Song(unsigned short bpm, Note notes[], unsigned short notes_count, unsigned short note_gap);
};


#endif //EVERLASTING_BIRTHDAY_CARD_SONG_H
