#ifndef EVERLASTING_BIRTHDAY_CARD_SONG_H
#define EVERLASTING_BIRTHDAY_CARD_SONG_H

#include "../Note/Note.h"

class Song {
public:
    Song(const Note *notes, unsigned short notes_count, unsigned char note_gap, unsigned short bpm) {
        this->notes = notes;
        this->notes_count = notes_count;
        this->note_gap = note_gap;

        // Precalculate bar duration:
        this->bar_duration = (static_cast<float>(60) / bpm) * 3 * 1000;  // duration of a full note (the whole bar)
    };

    const Note *getNotes() const {
        return this->notes;
    }

    unsigned short getNotesCount() const {
        return this->notes_count;
    }

    unsigned char getNoteGap() const {
        return this->note_gap;
    }

    float getBarDuration() const {
        return this->bar_duration;
    }

private:
    /// Array of song notes.
    const Note *notes;

    /// Number of notes in the song.
    unsigned short notes_count;

    /// Time gap between notes in ms (to avoid legato).
    unsigned char note_gap;

    /// Duration of one bar.
    float bar_duration;
};


#endif //EVERLASTING_BIRTHDAY_CARD_SONG_H
