#ifndef EVERLASTING_BIRTHDAY_CARD_NOTE_H
#define EVERLASTING_BIRTHDAY_CARD_NOTE_H

// Note tones:
// (https://pages.mtu.edu/~suits/notefreqs.html)

const unsigned short TONE_G3 = 196;
const unsigned short TONE_A3 = 220;
const unsigned short TONE_B3 = 247;
const unsigned short TONE_C4 = 262;
const unsigned short TONE_D4 = 294;
const unsigned short TONE_E4 = 330;
const unsigned short TONE_F4 = 349;
const unsigned short TONE_G4 = 392;

/// Represents note duration (half, quarter or eighth note).
enum NoteDuration {
    NOTE_DURATION_HALF,
    NOTE_DURATION_QUARTER,
    NOTE_DURATION_EIGHTH,
};

/// Represents note which have tone and duration.
struct Note {
    unsigned short tone;
    NoteDuration duration;
};


#endif //EVERLASTING_BIRTHDAY_CARD_NOTE_H
