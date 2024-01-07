#include "Buzzer.h"
#include "Arduino.h"


Buzzer::Buzzer(unsigned short pin) : pin(pin), song(nullptr) {}

void Buzzer::initPin() const {
    pinMode(this->pin, OUTPUT);
}

BuzzerState Buzzer::getState() const {
    return this->state;
}

void Buzzer::startTicking(int interval, int duration, int tone, unsigned char count) {
    this->tick_interval = interval;
    this->tick_duration = duration;
    this->tick_tone = tone;
    this->tick_count = count;

    this->tick_streak = 0;

    this->state = BUZZER_STATE_TICK;
}

void Buzzer::startSong(Song *song, unsigned char count) {
    this->song = song;
    this->song_count = count;

    this->song_note_index = 0;
    this->song_streak = 0;

    this->state = BUZZER_STATE_SONG;
}

void Buzzer::handleTick() {
    const unsigned long now = millis();

    if (!this->is_playing) {
        if (now >= this->tick_start_ts) {
//            this->tick_start_ts = now; todo: try toggling this line
            tone(this->pin, this->tick_tone);
            this->is_playing = true;
        }
        return;
    }

    if (now - this->tick_start_ts >= this->tick_duration) {
        noTone(this->pin);
        this->is_playing = false;
        this->tick_streak++;

        if (this->tick_streak >= this->tick_count) { // check if desired amount of ticks has been reached
            this->reset();
            return;
        }

        this->tick_start_ts = now + this->tick_interval;
    }
}

//void Buzzer::abortTick() {
//    this->playing = false;
//    this->state = BUZZER_STATE_STANDBY;
//}

void Buzzer::handleSong() {
    const unsigned long now = millis();
    const Note current_note = this->song->getNotes()[this->song_note_index];

    if (!this->is_playing) {
        if (now >= this->song_note_start_ts) {
//            this->song_note_start_ts = now; todo: try toggling this line of code
            tone(this->pin, current_note.tone);
            this->is_playing = true;
        }
        return;
    }

    // Calculate appropriate note duration in ms:
    // todo: maybe store durations.
    unsigned short current_note_duration_ms;
    switch (current_note.duration) {
        case NOTE_DURATION_HALF:
            current_note_duration_ms = static_cast<unsigned short>(this->song->getBarDuration() / 2);
            break;

        case NOTE_DURATION_QUARTER:
            current_note_duration_ms = static_cast<unsigned short>(this->song->getBarDuration() / 4);
            break;

        case NOTE_DURATION_EIGHTH:
            current_note_duration_ms = static_cast<unsigned short>(this->song->getBarDuration() / 8);
            break;
    }

    // If it is time to play next note:
    if (now - this->song_note_start_ts >= current_note_duration_ms) {
        noTone(this->pin);
        this->is_playing = false;

        if (this->song_note_index == this->song->getNotesCount() - 1) { // if the note stopped playing was the last one
            this->song_streak++;
            if (this->song_streak == this->song_count) { // if song has played desired amount of times
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

void Buzzer::reset() {
    this->is_playing = false;
    this->state = BUZZER_STATE_STANDBY;
}
