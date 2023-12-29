#ifndef EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H
#define EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H


class Microphone {
public:
    explicit Microphone(unsigned short pin);

    void init_pin() const;

    bool is_triggered(unsigned short treshold, unsigned short target);

private:
    unsigned short pin;
    unsigned short trigger_streak = 0;

    int read() const;
};


#endif //EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H
