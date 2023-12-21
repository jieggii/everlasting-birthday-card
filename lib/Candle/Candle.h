#ifndef EVERLASTING_BIRTHDAY_CARD_CANDLE_H
#define EVERLASTING_BIRTHDAY_CARD_CANDLE_H


class Candle {
public:
    unsigned short pin;

    explicit Candle(unsigned short pin);

    void init() const;

    void set_state(bool state) const;
};


#endif //EVERLASTING_BIRTHDAY_CARD_CANDLE_H
