#include "Buzzer.h"
#include "Arduino.h"
#include "settings.h"

// Note durations in ms:
const float DURATION_FULL = (static_cast<float>(60) / SONG_BPM) * 3 * 1000;
const float DURATION_HALF = DURATION_FULL/2;
const float DURATION_QUARTER = DURATION_FULL/4;
const float DURATION_EIGHTH = DURATION_FULL/8;

// Note tones:
// (source: https://pages.mtu.edu/~suits/notefreqs.html)
const unsigned short TONE_A3 = 220;
const unsigned short TONE_B3 = 247;
const unsigned short TONE_G3 = 196;
const unsigned short TONE_C4 = 262;
const unsigned short TONE_D4 = 294;
const unsigned short TONE_E4 = 330;
const unsigned short TONE_F4 = 349;
const unsigned short TONE_G4 = 392;

class Note {
public:
    unsigned short tone;
    float duration;

    Note(unsigned short tone, float duration);
};

Note::Note(unsigned short tone, float duration) {
    this->duration = duration;
    this->tone = tone;
}

// https://musescore.com/user/173585/scores/166951
const Note SONG[] = {
        // Bar 1:
        Note(TONE_G3, DURATION_EIGHTH),
        Note(TONE_G3, DURATION_EIGHTH),
        Note(TONE_A3, DURATION_QUARTER),
        Note(TONE_G3, DURATION_QUARTER),

        // Bar 2:
        Note(TONE_C4, DURATION_QUARTER),
        Note(TONE_B3, DURATION_FULL),

        // Bar 3:
        Note(TONE_G3, DURATION_EIGHTH),
        Note(TONE_G3, DURATION_EIGHTH),
        Note(TONE_A3, DURATION_QUARTER),
        Note(TONE_G3, DURATION_QUARTER),

        // Bar 4:
        Note(TONE_D4, DURATION_QUARTER),
        Note(TONE_C4, DURATION_FULL),

        // Bar 5:
        Note(TONE_G3, DURATION_EIGHTH),
        Note(TONE_G3, DURATION_EIGHTH),
        Note(TONE_G4, DURATION_QUARTER),
        Note(TONE_E4, DURATION_QUARTER),

        // Bar 6:
        Note(TONE_C4, DURATION_QUARTER),
        Note(TONE_B3, DURATION_QUARTER),
        Note(TONE_A3, DURATION_QUARTER),

        // Bar 7:
        Note(TONE_F4, DURATION_EIGHTH),
        Note(TONE_F4, DURATION_EIGHTH),
        Note(TONE_E4, DURATION_QUARTER),
        Note(TONE_C4, DURATION_QUARTER),

        // Bar 8:
        Note(TONE_D4, DURATION_QUARTER),
        Note(TONE_C4, DURATION_HALF),
};

Buzzer::Buzzer(unsigned short pin) {
    this->pin = pin;
}

void Buzzer::init() {
    pinMode(pin, OUTPUT);
}

void Buzzer::draw_attention() {
    for (int i = 0; i < 3; i++) {
        tone(this->pin, 3000);
        delay(500);
        noTone(this->pin);
    }
}

void Buzzer::play_happy_birthday_song() {
    for (auto note : SONG) {
        tone(this->pin, note.tone);
        delay(static_cast<unsigned long>(note.duration));
        noTone(this->pin);
//        delay(10);
    }
}
