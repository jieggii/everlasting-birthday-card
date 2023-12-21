#ifndef EVERLASTING_BIRTHDAY_CARD_BUZZER_H
#define EVERLASTING_BIRTHDAY_CARD_BUZZER_H

#include "../Song/Song.h"


enum BuzzerState {
    // The default mode, nothing is being played.
    BUZZER_STATE_STANDBY,

    // Song is being played.
    BUZZER_STATE_SONG,

    // Constant ticker is playing.
    BUZZER_STATE_TICKING,
};

class Buzzer {
public:
    // Songs played in a row counter.
    // unsigned long song_streak = 0;

    // Amount of ticks played in a row.
    unsigned short tick_streak = 0;

    Buzzer(unsigned short pin, Song song);

    // Initialize buzzer.
    void init() const;

    // Start repeatedly playing song.
    void start_song();

    // Gracefully finishes song (playing till the end);
    void finish_song();

    // Start ticking.
    void start_ticking(int interval, int duration, int tone);

    // Finish ticking.
    void finish_ticking();


    void handle();


private:
    // Output pin number.
    unsigned short pin;

    // Song which buzzer will be able to play.
    Song song;

    // Is true when buzzer is producing sound, false when buzzer is silent.
    bool playing = false;

    // Buzzer state
    BuzzerState state = BUZZER_STATE_STANDBY;


    // Related to BUZZER_STATE_TICKING state:

    // Interval of tick in BUZZER_STATE_TICKING.
    unsigned short tick_interval = 0;

    // Duration of tick in BUZZER_STATE_TICKING.
    unsigned short tick_duration = 0;

    // Tone of tick in BUZZER_STATE_TICKING.
    unsigned short tick_tone = 0;

    // Timestamp when the current tick started.
    unsigned long tick_start_ts = 0;

    // Whether tick will be played next time or not.
    bool tick_play_next = false;


    // Related to BUZZER_STATE_SONG state:

    // Whether song be played next time or not.
    bool song_play_next = false;

    // Index of the current note in the song.
    unsigned short song_note_index = 0;

    // Timestamp when the current note started playing.
    unsigned long song_note_start_ts = 0;

    // Handles song.
    void handle_song();

    // Resets buzzer, interrupts song.
    void abort_song();

    // Handles ticking.
    void handle_ticking();

    // Resets from ticker to the standby state.
    void abort_ticking();
};


#endif //EVERLASTING_BIRTHDAY_CARD_BUZZER_H
