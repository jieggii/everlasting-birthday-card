#include "Buzzer.h"
#include "Arduino.h"


Buzzer::Buzzer(uint8_t pin) : pin(pin), song(nullptr) {}

/// Sets OUTPUT mode for the buzzer pin.
void Buzzer::initPin() const {
    pinMode(this->pin, OUTPUT);
}

/// Calls Tone function over buzzer's pin.
void Buzzer::tone(unsigned int frequency) const {
    ::tone(this->pin, frequency);
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

    this->song_streak = 0;

    this->song_current_note_index = 0;
    this->song_start = true;

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

    // begin playing song if it is the first time when handleSong was called after initSong:
    if (this->song_start) {
        this->song_start = false;

        // set current note and its duration in ms:
        this->song_current_note_index = 0;
        this->song_current_note = this->song->getNote(this->song_current_note_index);
        this->song_current_note_duration_ms = this->song->getNoteDurationMs(this->song_current_note.duration);

        // start playing the first note
        this->song_current_note_start_ts = now;
        this->is_playing = true;
        this->tone(song_current_note.tone);

        return;
    }

    if (now - this->song_current_note_start_ts >=
        this->song_current_note_duration_ms) {  // if it is time to play next note
        // if the note which finishes its duration was the last one:
        if (this->song_current_note_index == this->song->getNotesCount() - 1) {
            this->song_streak++; // increment counter of songs played
            if (this->song_streak >= this->song_count) { // if song has played more or equal to desired amount of times
                // (>= is used instead of == because finishSong sets song_count to 0)
                this->reset();
                return;
            }
            this->song_current_note_index = 0; // reset note index to 0 in order to play song again
        } else {
            this->song_current_note_index++;
        }

        this->song_current_note = this->song->getNote(this->song_current_note_index);
        this->song_current_note_start_ts = now;
        this->is_playing = true;
        if (this->song_current_note.tone != TONE_REST) {
            this->tone(this->song_current_note.tone);
        }
        this->song_current_note_duration_ms = this->song->getNoteDurationMs(this->song_current_note.duration);
    } else if (now - this->song_current_note_start_ts >=
               this->song_current_note_duration_ms - this->song->getNoteGap() &&
               this->is_playing) { // if it is time to finish current note
        this->noTone();
        this->is_playing = false;
        Serial.println("stop note " + String(this->song_current_note_index));
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
