#ifndef EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H
#define EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H

#include "stdint.h"

/// Represents a physical microphone module.
class Microphone {
public:
    explicit Microphone(uint8_t pin);

    void initPin() const;

    bool isTriggered(unsigned short treshold, uint8_t streak);

private:
    /// Microphone analog data input pin.
    uint8_t pin;

    /// Amount of triggers in a row.
    uint8_t trigger_streak;
};


#endif //EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H
