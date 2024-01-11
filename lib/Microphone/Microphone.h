#ifndef EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H
#define EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H


class Microphone {
public:
    explicit Microphone(unsigned char pin);

    /// Initialize microphone analog input pin.
    void initPin() const;

    /// Returns true if the given `treshold` has been reached or exceeded `streak` times in a row.
    bool isTriggered(unsigned short treshold, unsigned short streak);

private:
    /// Microphone analog data input pin.
    unsigned char pin;

    /// Amount of triggers in a row.
    unsigned short trigger_streak;
};


#endif //EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H
