#ifndef EVERLASTING_BIRTHDAY_CARD_CANDLE_H
#define EVERLASTING_BIRTHDAY_CARD_CANDLE_H


class Candle {
public:
    /// Indicates whether the candle LED turn_on or turn_off.
    bool powered = false;

    explicit Candle(unsigned short pin);

    void init_pin() const;

    /// Turn turn_on the candle.
    void turn_on();

    /// Turn turn_off the candle.
    void turn_off();

private:
    unsigned short pin;

    void set_powered(bool new_state);
};


#endif //EVERLASTING_BIRTHDAY_CARD_CANDLE_H
