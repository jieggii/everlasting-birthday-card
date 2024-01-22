#include "Buzzer.h"
#include "Arduino.h"


Buzzer::Buzzer(uint8_t pin) : pin(pin), song(nullptr) {}

/// Sets OUTPUT mode for the buzzer pin.
void Buzzer::initPin() const {
    pinMode(this->pin, OUTPUT);
}

/// Calls Tone function over buzzer's pin.
void Buzzer::tone(unsigned int frequency) const {
//    ::tone(this->pin, frequency);
}

/// Calls noTone function over buzzer's pin.
void Buzzer::noTone() const {
    ::noTone(this->pin);
}

/// Returns current state of the buzzer.
BuzzerState Buzzer::getState() const {
    return this->state;
}

/// Sets up a song which should be played, puts buzzer into PLAYING_SONG state.
void Buzzer::initSong(const Song *song, uint8_t count) {
    this->song = song;
    this->song_count = count;

    this->song_note_index = 0;
    this->song_streak = 0;

    this->state = BuzzerState::PLAYING_SONG;
}

/// Sets up ticking settings, puts buzzer into PLAYING_TICK state.
void Buzzer::initTick(int interval, int duration, int tone, uint8_t count) {
    this->tick_interval = interval;
    this->tick_duration = duration;
    this->tick_tone = tone;
    this->tick_count = count;

    this->tick_streak = 0;

    this->state = BuzzerState::PLAYING_TICK;
}

/// Gracefully finishes song playing (plays the last time till the end).
void Buzzer::finishSong() {
    this->song_count = 0;
}

/// Handles tick playing (must be called in a loop).
void Buzzer::handleTick() {
    if (this->state != BuzzerState::PLAYING_TICK) {
        return;
    }

    const unsigned long now = millis();

    if (!this->is_playing) {
        if (now >= this->tick_start_ts) {
            this->tick_start_ts = now;
            this->tone(this->tick_tone);
            this->is_playing = true;
        }
        return;
    }

    if (now - this->tick_start_ts >= this->tick_duration) {
        this->noTone();
        this->is_playing = false;
        this->tick_streak++;

        if (this->tick_streak == this->tick_count) { // check if desired amount of ticks has been reached
            this->reset();
            return;
        }
        this->tick_start_ts = now + this->tick_interval;
    }
}

/// Handles song playing (must be called in a loop).
void Buzzer::handleSong() {
    if (this->state != BuzzerState::PLAYING_SONG) {
        return;
    }

    const unsigned long now = millis();
    const Note current_note = this->song->getNotes()[this->song_note_index];

    if (!this->is_playing) {
        if (now >= this->song_note_start_ts) {
            this->song_note_start_ts = now;
            this->tone(current_note.tone);
            this->is_playing = true;
        }
        return;
    }

    // Calculate appropriate note duration in ms:
    unsigned short current_note_duration_ms;
    switch (current_note.duration) {
        case NOTE_DURATION_HALF:
            current_note_duration_ms = this->song->getHalfDuration();
            break;

        case NOTE_DURATION_QUARTER:
            current_note_duration_ms = this->song->getQuarterDuration();
            break;

        case NOTE_DURATION_EIGHTH:
            current_note_duration_ms = this->song->getEighthDuration();
            break;
    }

    // If it is time to play next note:
    if (now - this->song_note_start_ts >= current_note_duration_ms) {
        this->noTone();
        this->is_playing = false;

        if (this->song_note_index == this->song->getNotesCount() - 1) { // if the note stopped playing was the last one
            this->song_streak++;
            if (this->song_streak >= this->song_count) { // if song has played desired amount of times
                // (>= is used instead of == because finishSong sets song_count to 0)
                this->reset();
                return;
            }
            this->song_note_index = 0; // reset note index to 0 in order to play song again
        } else {
            this->song_note_index++;
        }
        this->song_note_start_ts = now + this->song->getNoteGap();
    }
}

/// General handling method choosing what to play according to the buzzer state (must be called in a loop).
void Buzzer::handle() {
    switch (this->state) {
        case BuzzerState::STANDBY:
            return;

        case BuzzerState::PLAYING_SONG:
            this->handleSong();
            break;

        case BuzzerState::PLAYING_TICK:
            this->handleTick();
            break;
    }
}

/// Resets buzzer to the STANDBY state.
void Buzzer::reset() {
    this->is_playing = false;
    this->state = BuzzerState::STANDBY;
}
