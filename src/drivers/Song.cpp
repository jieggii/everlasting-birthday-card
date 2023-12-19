#include "Song.h"



Song::Song(unsigned short bpm, Note *notes, unsigned short notes_count, unsigned short note_gap) {
    this->bpm = bpm;
    this->notes = notes;
    this->notes_count = notes_count;
    this->note_gap = note_gap;

    // Precalculate durations for different notes:
    float full_duration = (static_cast<float>(60) / bpm) * 3 * 1000;

    this->half_duration = static_cast<unsigned int>(full_duration/2);
    this->quarter_duration = static_cast<unsigned int>(full_duration/4);
    this->eighth_duration = static_cast<unsigned int>(full_duration/8);
}