#include "Buzzer.h"
#include "Arduino.h"


Buzzer::Buzzer(unsigned short pin) {
    this->pin = pin;
    this->song = nullptr;
}

void Buzzer::initPin() const {
    pinMode(this->pin, OUTPUT);
}

void Buzzer::startTicking(int interval, int duration, int tone) {
    this->tick_interval = interval;
    this->tick_duration = duration;
    this->tick_tone = tone;

    this->tick_play_next = true;
    this->state = BUZZER_STATE_TICK;
}

void Buzzer::startSong(Song *song) {
    this->song = song;
    this->song_play_next = true;
    this->state = BUZZER_STATE_SONG;
}

void Buzzer::handleTick() {
    const unsigned long now = millis();

    if (!this->playing) {
        if (now >= this->tick_start_ts) {
            this->tick_start_ts = now;
            tone(this->pin, this->tick_tone);
            this->playing = true;
            this->tick_streak++;
        }
        return;
    }

    if (now >= this->tick_start_ts + this->tick_duration) {
        noTone(this->pin);
        this->playing = false;
        if (this->tick_play_next) { // todo: check if this logic needed
            this->tick_start_ts = now + this->tick_interval;
        }
    }
}

void Buzzer::handleSong() {
    const unsigned long now = millis();
    const Note current_note = this->song->notes[this->song_note_index];

    if (!this->playing) {
        if (now >= this->song_note_start_ts) {
            this->song_note_start_ts = now;
            this->playing = true;
            tone(this->pin, current_note.tone);
        }
    }

    // Get appropriate note duration in ms:
    unsigned int current_note_duration_ms;
    switch (current_note.duration) {
        case NOTE_DURATION_HALF:
            current_note_duration_ms = this->song->half_duration;
            break;

        case NOTE_DURATION_QUARTER:
            current_note_duration_ms = this->song->quarter_duration;
            break;

        case NOTE_DURATION_EIGHTH:
            current_note_duration_ms = this->song->eighth_duration;
            break;
    }

    // If it is time to play next note:
    if (now >= this->song_note_start_ts + current_note_duration_ms) {
        this->song_note_index++;
        this->playing = false;
        noTone(this->pin);

        // If the last note has been played already:
        if (this->song_note_index > this->song->notes_count - 1) {
            if (this->song_play_next) {
                this->song_note_index = 0;
            } else {
                this->abortSong();
            }
        }
        this->song_note_start_ts = now + this->song->note_gap;
    }
}


void Buzzer::handle() {
    switch (this->state) {
        case BUZZER_STATE_STANDBY:
            return;

        case BUZZER_STATE_SONG:
            this->handleSong();
            break;

        case BUZZER_STATE_TICK:
            this->handleTick();
            break;
    }
}

void Buzzer::abortTick() {
    this->state = BUZZER_STATE_STANDBY;
    this->playing = false;

    this->tick_streak = 0;
    this->tick_interval = 0;
    this->tick_duration = 0;
    this->tick_tone = 0;

    this->tick_start_ts = 0;
}

void Buzzer::abortSong() {
    this->state = BUZZER_STATE_STANDBY;
    this->playing = false;

    this->song_note_index = 0;
    this->song_note_start_ts = 0;
}

void Buzzer::finishTicking() {
    this->abortTick();
}

void Buzzer::finishSong() {
    this->song_play_next = false;
}
