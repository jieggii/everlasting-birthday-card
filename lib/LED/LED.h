#ifndef EVERLASTING_BIRTHDAY_CARD_LED_H
#define EVERLASTING_BIRTHDAY_CARD_LED_H

/// Represents a physical LED.
class LED {
public:
    explicit LED(uint8_t pin);

    void initPin() const;

    bool isPowered() const {
        return this->is_powered;
    }

    void turnOn();

    void turnOff();


private:
    /// Pin number.
    uint8_t pin;

    /// Indicates whether the candle LED turned on or turned off.
    bool is_powered = false;

    /// Sets new LED state, also updates `powered` variable.
    void update_state(bool new_state);
};


#endif //EVERLASTING_BIRTHDAY_CARD_LED_H
