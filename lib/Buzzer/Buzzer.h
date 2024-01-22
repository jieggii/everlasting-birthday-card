#ifndef EVERLASTING_BIRTHDAY_CARD_BUZZER_H
#define EVERLASTING_BIRTHDAY_CARD_BUZZER_H

#include "stdint.h"
#include "../Song/Song.h"


enum BuzzerState {
    /// The default stand by mode, nothing is being played.
    STANDBY,

    /// Song is being played.
    PLAYING_SONG,

    /// Ticking sound is being played.
    PLAYING_TICK,
};

class Buzzer {
public:
    explicit Buzzer(uint8_t pin);

    /// Initialize output pin for buzzer.
    void initPin() const;

    /// Call `tone` function from Arduino stdlib over the buzzer pin.
    void tone(unsigned int frequency) const;

    /// Cal `noTone` function from Arduino stdlib over the buzzer pin.
    void noTone() const;

    /// Returns current state of the buzzer.
    BuzzerState getState() const;

    /// Start repeatedly playing song.
    void initSong(const Song *song, uint8_t count);

    /// Begin ticking.
    void initTick(int interval, int duration, int tone, uint8_t count);

    /// Gracefully finish playing song before song streak is reached.
    void finishSong();

    /// General method to handle buzzer.
    void handle();


private:
    /// Output pin number.
    uint8_t pin;

    /// Current buzzer state.
    BuzzerState state = STANDBY;

    /// Is true when buzzer is producing sound, false when buzzer is silent.
    bool is_playing = false;

    // Related to BUZZER_STATE_TICK state:
    /// Amount of ticks to be played.
    uint8_t tick_count = 0;

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
    /// Song which is being played by the buzzer.
    Song const *song;

    /// Amount of times song must be played.
    unsigned short song_count = 0;

    /// Amount of song being played in a row at the moment.
    unsigned short song_streak = 0;

    /// Index of the current note in the song.
    uint8_t song_note_index = 0;

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
