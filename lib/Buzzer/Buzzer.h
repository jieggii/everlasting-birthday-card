#ifndef EVERLASTING_BIRTHDAY_CARD_BUZZER_H
#define EVERLASTING_BIRTHDAY_CARD_BUZZER_H

#include "../Song/Song.h"


enum BuzzerState {
    /// The default stand by mode, nothing is being played.
    BUZZER_STATE_STANDBY,

    /// Song is being played.
    BUZZER_STATE_SONG,

    /// Ticking sound is being played.
    BUZZER_STATE_TICK,
};

class Buzzer {
public:
    explicit Buzzer(unsigned short pin);

    /// Initialize output pin for buzzer.
    void initPin() const;

    /// Returns current state of the buzzer.
    BuzzerState getState() const;

    /// Start repeatedly playing song.
    void startSong(Song *song, unsigned char count);

    /// Start ticking.
    void startTicking(int interval, int duration, int tone, unsigned char count);

    /// General method to handle buzzer.
    void handle();


private:
    /// Output pin number.
    unsigned short pin;

    /// Current buzzer state.
    BuzzerState state = BUZZER_STATE_STANDBY;

    /// Is true when buzzer is producing sound, false when buzzer is silent.
    bool is_playing = false;

    // Related to BUZZER_STATE_TICK state:
    /// Amount of ticks to be played.
    unsigned char tick_count = 0;

    /// Amount of ticks played in a row at the moment.
    unsigned short tick_streak = 0;

    /// Interval of tick in BUZZER_STATE_TICKING.
    unsigned short tick_interval = 0;

    /// Duration of tick in BUZZER_STATE_TICKING.
    unsigned short tick_duration = 0;

    /// Tone of tick in BUZZER_STATE_TICKING.
    unsigned short tick_tone = 0;

    /// Timestamp when the current tick started.
    unsigned long tick_start_ts = 0;


    // Related to BUZZER_STATE_SONG state:
    /// Song which is being played by buzzer.
    Song *song;

    /// Amount of times song must be played.
    unsigned short song_count = 0;

    /// Amount of song being played in a row at the moment.
    unsigned short song_streak = 0;

    /// Index of the current note in the song.
    unsigned char song_note_index = 0;

    /// Timestamp when the current note started playing.
    unsigned long song_note_start_ts = 0;

    /// Handles playing song.
    void handleSong();

    /// Handles ticking.
    void handleTick();

    /// Reset buzzer to STANDBY state (abort playing song or ticking).
    void reset();
};


#endif //EVERLASTING_BIRTHDAY_CARD_BUZZER_H
