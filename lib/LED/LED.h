#ifndef EVERLASTING_BIRTHDAY_CARD_LED_H
#define EVERLASTING_BIRTHDAY_CARD_LED_H


class LED {
public:
    explicit LED(unsigned char pin);

    /// Set appropriate pin mode for the LED pin.
    void initPin() const;

    /// Returns true when LED is powered, false otherwise.
    bool isPowered() const {
        return this->is_powered;
    }

    /// Turn turnOn the candle.
    void turnOn();

    /// Turn turnOff the candle.
    void turnOff();


private:
    /// Pin number.
    unsigned char pin;

    /// Indicates whether the candle LED turned on or turned off.
    bool is_powered = false;

    /// Sets new LED state, also updates `powered` variable.
    void update_state(bool new_state);
};


#endif //EVERLASTING_BIRTHDAY_CARD_LED_H
