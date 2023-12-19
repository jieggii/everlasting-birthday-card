#ifndef EVERLASTING_BIRTHDAY_CARD_CANDLE_H
#define EVERLASTING_BIRTHDAY_CARD_CANDLE_H


class Candle {
public:
    unsigned short pin;

    explicit Candle(unsigned short pin);
    void init();
    void set_state(bool state);
};


#endif //EVERLASTING_BIRTHDAY_CARD_CANDLE_H
