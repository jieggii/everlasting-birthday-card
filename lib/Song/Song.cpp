#include "Song.h"


Song::Song(const Note *notes, unsigned short notes_count, uint8_t note_gap, unsigned short bpm) {
    this->notes = notes;
    this->notes_count = notes_count;
    this->note_gap = note_gap;

    // Precalculate note durations:
    float full_duration = (static_cast<float>(60) / bpm) * 3 * 1000;  // duration of a full note (the whole bar)
    this->half_duration = static_cast<unsigned short>(full_duration / 2);
    this->quarter_duration = static_cast<unsigned short>(full_duration / 4);
    this->eighth_duration = static_cast<unsigned short>(full_duration / 8);
};

/// Returns array of notes of the song.
const Note *Song::getNotes() const {
    return this->notes;
}

/// Returns amount of notes in the song.
unsigned short Song::getNotesCount() const {
    return this->notes_count;
}

/// Returns gap between notes.
uint8_t Song::getNoteGap() const {
    return this->note_gap;
}

/// Returns duration of a half note in ms.
unsigned short Song::getHalfDuration() const {
    return this->half_duration;
}

/// Returns duration of a quarter note in ms.
unsigned short Song::getQuarterDuration() const {
    return this->quarter_duration;
}

/// Returns duration of an eighth note in ms.
unsigned short Song::getEighthDuration() const {
    return this->eighth_duration;
}
