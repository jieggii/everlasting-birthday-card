#ifndef EVERLASTING_BIRTHDAY_CARD_CANDLE_H
#define EVERLASTING_BIRTHDAY_CARD_CANDLE_H


class Candle {
public:
    explicit Candle(unsigned short pin);

    /// Set appropriate pin mode for the LED pin.
    void init_pin() const;

    /// Turn turn_on the candle.
    void turn_on();

    /// Turn turn_off the candle.
    void turn_off();

    /// Returns true when LED is powered, false otherwise.
    bool getIsPowered() const {
        return this->is_powered;
    }

private:
    /// Pin number.
    unsigned short pin;

    /// Indicates whether the candle LED turned on or turned off.
    bool is_powered = false;

    /// Sets new LED state, also updates `powered` variable.
    void update_state(bool new_state);
};


#endif //EVERLASTING_BIRTHDAY_CARD_CANDLE_H
