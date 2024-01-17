#ifndef EVERLASTING_BIRTHDAY_CARD_SONG_H
#define EVERLASTING_BIRTHDAY_CARD_SONG_H

#include "../Note/Note.h"

class Song {
public:
    Song(const Note *notes, unsigned short notes_count, unsigned char note_gap, unsigned short bpm);

    const Note *getNotes() const;

    unsigned short getNotesCount() const;

    unsigned char getNoteGap() const;

    unsigned short getHalfDuration() const;

    unsigned short getQuarterDuration() const;

    unsigned short getEighthDuration() const;


private:
    /// Array of song notes.
    const Note *notes;

    /// Number of notes in the song.
    unsigned short notes_count;

    /// Time gap between notes in ms (to avoid legato).
    unsigned char note_gap;

    /// Duration of a half note in ms.
    unsigned short half_duration;

    /// Duration of a quarter note in ms.
    unsigned short quarter_duration;

    /// Duration of an eighth note in ms.
    unsigned short eighth_duration;
};

#endif //EVERLASTING_BIRTHDAY_CARD_SONG_H
