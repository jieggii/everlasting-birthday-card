#include "avr/pgmspace.h"

#include "Song.h"

Song::Song(const Note *notes, unsigned short notes_count, uint8_t note_gap, unsigned short bpm,
           uint8_t quarters_count) {
    this->notes = notes;
    this->notes_count = notes_count;
    this->note_gap = note_gap;

    // Precalculate note durations:
    float full_duration =
            (static_cast<float>(60) / bpm) * quarters_count * 1000;  // duration of a whole bar with good precision

    this->whole_duration = static_cast<unsigned short>(full_duration);
    this->half_duration = static_cast<unsigned short>(full_duration / 2);
    this->quarter_duration = static_cast<unsigned short>(full_duration / 4);
    this->eighth_duration = static_cast<unsigned short>(full_duration / 8);
    this->sixteenth_duration = static_cast<unsigned short>(full_duration / 16);
    this->thirty_second_duration = static_cast<unsigned short>(full_duration / 32);
}

/// Returns amount of notes in the song.
unsigned short Song::getNotesCount() const {
    return this->notes_count;
}

/// Returns gap between notes.
uint8_t Song::getNoteGap() const {
    return this->note_gap;
}

Note Song::getNote(unsigned short index) const {
    Note note;
//    Note note{};
    memcpy_P(&note, &this->notes[index], sizeof(Note));
    return note;
}

/// Returns duration of a note in ms based on its duration type.
unsigned short Song::getNoteDurationMs(NoteDuration duration) const {
    switch (duration) {
        case NoteDuration::WHOLE:
            return this->whole_duration;
        case NoteDuration::HALF:
            return this->half_duration;
        case NoteDuration::QUARTER:
            return this->quarter_duration;
        case NoteDuration::EIGHTH:
            return this->eighth_duration;
        case NoteDuration::SIXTEENTH:
            return this->sixteenth_duration;
        case NoteDuration::THIRTY_SECOND:
            return this->thirty_second_duration;
    }
    return 0;
}
