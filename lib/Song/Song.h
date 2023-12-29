#ifndef EVERLASTING_BIRTHDAY_CARD_SONG_H
#define EVERLASTING_BIRTHDAY_CARD_SONG_H

#include "../Note/Note.h"

class Song {
public:
    /// Array of song notes.
    Note *notes;

    /// Number of notes in the song.
    unsigned short notes_count;

    /// Time gap between notes in ms (to avoid legato).
    unsigned short note_gap;

    /// Duration of a half note in ms.
    unsigned int half_duration;

    /// Duration of a quarter note in ms.
    unsigned int quarter_duration;

    /// Duration of an eighth note in ms.
    unsigned int eighth_duration;

    Song(unsigned short bpm, Note notes[], unsigned short notes_count, unsigned short note_gap) {
        this->notes = notes;
        this->notes_count = notes_count;
        this->note_gap = note_gap;

        // Precalculate durations for different notes:
        float full_duration = (static_cast<float>(60) / bpm) * 3 * 1000;  // duration of a full note (the whole bar)

        this->half_duration = static_cast<unsigned int>(full_duration / 2);    // duration of a half note
        this->quarter_duration = static_cast<unsigned int>(full_duration / 4); // duration of a quarter note
        this->eighth_duration = static_cast<unsigned int>(full_duration / 8);  // duration of an eighth note
    };
};


#endif //EVERLASTING_BIRTHDAY_CARD_SONG_H
