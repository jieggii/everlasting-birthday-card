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
    /// Buzzer state.
    BuzzerState state = BUZZER_STATE_STANDBY;

    /// Amount of ticks played in a row.
    unsigned short tick_streak = 0;

    /// Amount of song being played in a row.
    unsigned short song_streak = 0;


    explicit Buzzer(unsigned short pin);

    /// Initialize output pin for buzzer.
    void initPin() const;

    /// Start repeatedly playing song.
    void startSong(Song *song);

    /// Gracefully finishes song (playing till the end).
    void finishSong();

    /// Start ticking.
    void startTicking(int interval, int duration, int tone);

    /// Finish ticking.
    void finishTicking();

    /// Abort playing song.
    void abortSong();

    /// General method to handle buzzer.
    void handle();


private:
    /// Output pin number.
    unsigned short pin;

    /// Song which is being played by buzzer.
    Song *song;

    /// Is true when buzzer is producing sound, false when buzzer is silent.
    bool playing = false;

    // Related to BUZZER_STATE_TICK state:

    /// Interval of tick in BUZZER_STATE_TICKING.
    unsigned short tick_interval = 0;

    /// Duration of tick in BUZZER_STATE_TICKING.
    unsigned short tick_duration = 0;

    /// Tone of tick in BUZZER_STATE_TICKING.
    unsigned short tick_tone = 0;

    /// Timestamp when the current tick started.
    unsigned long tick_start_ts = 0;

    /// Whether tick will be played next time or not.
    bool tick_play_next = false;

    // Related to BUZZER_STATE_SONG state:

    /// Whether song be played next time or not.
    bool song_play_next = false;

    /// Index of the current note in the song.
    unsigned short song_note_index = 0;

    /// Timestamp when the current note started playing.
    unsigned long song_note_start_ts = 0;

    /// Handles song.
    void handleSong();

    /// Handles ticking.
    void handleTick();

    /// Resets from ticker to the standby powered.
    void abortTick();
};


#endif //EVERLASTING_BIRTHDAY_CARD_BUZZER_H
