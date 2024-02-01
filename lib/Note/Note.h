#ifndef EVERLASTING_BIRTHDAY_CARD_NOTE_H
#define EVERLASTING_BIRTHDAY_CARD_NOTE_H

/*
 Note tones.
 E.g: https://pages.mtu.edu/~suits/notefreqs.html
*/

/// Represents rest (no tone).
const unsigned short TONE_REST = 0;

const unsigned short TONE_G3 = 196;
const unsigned short TONE_A3 = 220;
const unsigned short TONE_Bb3 = 233;
const unsigned short TONE_B3 = 247;
const unsigned short TONE_C4 = 262;
const unsigned short TONE_Db4 = 277;
const unsigned short TONE_D4 = 294;
const unsigned short TONE_Eb4 = 311;
const unsigned short TONE_E4 = 330;
const unsigned short TONE_F4 = 349;
const unsigned short TONE_Gb4 = 370;
const unsigned short TONE_G4 = 392;
const unsigned short TONE_Ab4 = 415;
const unsigned short TONE_A4 = 440;
const unsigned short TONE_Bb4 = 466;
const unsigned short TONE_B4 = 494;
const unsigned short TONE_C5 = 523;
const unsigned short TONE_Db5 = 554;
const unsigned short TONE_D5 = 587;
const unsigned short TONE_Eb5 = 622;
const unsigned short TONE_E5 = 659;
const unsigned short TONE_F5 = 698;
const unsigned short TONE_Gb5 = 740;
const unsigned short TONE_G5 = 784;
const unsigned short TONE_Ab5 = 831;
const unsigned short TONE_Bb5 = 932;
const unsigned short TONE_B5 = 988;
const unsigned short TONE_C6 = 1047;
const unsigned short TONE_Db6 = 1109;
const unsigned short TONE_D6 = 1175;
const unsigned short TONE_Eb6 = 1245;
const unsigned short TONE_F6 = 1397;
const unsigned short TONE_Ab6 = 1661;

/// Represents note duration.
enum NoteDuration {
    WHOLE,
    HALF,
    QUARTER,
    EIGHTH,
    SIXTEENTH,
    THIRTY_SECOND
};

/// Represents a note.
struct Note {
    unsigned short tone;
    NoteDuration duration;
};


#endif //EVERLASTING_BIRTHDAY_CARD_NOTE_H
