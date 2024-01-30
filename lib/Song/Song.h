#ifndef EVERLASTING_BIRTHDAY_CARD_SONG_H
#define EVERLASTING_BIRTHDAY_CARD_SONG_H

#include "stdint.h"

#include "Note.h"


/// Represents song which should be played using buzzer.
class Song {
public:
    Song(const Note *notes, unsigned short notes_count, uint8_t note_gap, unsigned short bpm, uint8_t quarters_count);

    unsigned short getNotesCount() const;

    uint8_t getNoteGap() const;

    unsigned short getNoteDurationMs(NoteDuration duration) const;

    Note getNote(unsigned short index) const;


private:
    /// Array of song notes.
    const Note *notes;

    /// Number of notes in the song.
    unsigned short notes_count;

    /// Time gap between notes in ms (to avoid legato).
    uint8_t note_gap;

    /// Duration of a whole note in ms.
    unsigned short whole_duration;

    /// Duration of a half note in ms.
    unsigned short half_duration;

    /// Duration of a quarter note in ms.
    unsigned short quarter_duration;

    /// Duration of an eighth note in ms.
    unsigned short eighth_duration;

    /// Duration of a sixteenth note in ms.
    unsigned short sixteenth_duration;

    /// Duration of a thiry-second note in ms.
    unsigned short thirty_second_duration;
};

#endif //EVERLASTING_BIRTHDAY_CARD_SONG_H
