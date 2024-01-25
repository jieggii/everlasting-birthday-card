#ifndef EVERLASTING_BIRTHDAY_CARD_NOTE_H
#define EVERLASTING_BIRTHDAY_CARD_NOTE_H

// Note tones:
// (https://pages.mtu.edu/~suits/notefreqs.html)

const unsigned short TONE_REST = 0;

//const unsigned short TONE_B2b = 117;
//const unsigned short TONE_B2 = 123;

//const unsigned short TONE_C3 = 131;
//const unsigned short TONE_E3 = 165;
//const unsigned short TONE_F3 = 175;
const unsigned short TONE_G3 = 196;
const unsigned short TONE_A3 = 220;
const unsigned short TONE_B3 = 247;
const unsigned short TONE_C4 = 262;
const unsigned short TONE_D4 = 294;
const unsigned short TONE_E4 = 330;
//const unsigned short TONE_E4b = 311;
const unsigned short TONE_A4 = 440;
const unsigned short TONE_F4 = 349;
const unsigned short TONE_G4 = 392;
const unsigned short TONE_C5 = 523;
const unsigned short TONE_D5 = 587;
const unsigned short TONE_C6 = 1047;
const unsigned short TONE_G5 = 784;
const unsigned short TONE_F5 = 698;
const unsigned short TONE_D6 = 1175;
const unsigned short TONE_Bb3 = 233;
const unsigned short TONE_E5 = 659;
const unsigned short TONE_Eb5 = 622;


/// Represents note duration (half, quarter or eighth note).
enum NoteDuration {
    WHOLE,
    HALF,
    QUARTER,
    EIGHTH,
    SIXTEENTH,
};

/// Represents note which have tone and duration.
struct Note {
    unsigned short tone;
    NoteDuration duration;
};


#endif //EVERLASTING_BIRTHDAY_CARD_NOTE_H
