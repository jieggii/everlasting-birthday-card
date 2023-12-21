#ifndef EVERLASTING_BIRTHDAY_CARD_CANDLE_H
#define EVERLASTING_BIRTHDAY_CARD_CANDLE_H


class Candle {
public:
    unsigned short pin;
    bool powered = false;

    explicit Candle(unsigned short pin);

    void init() const;

    void set_powered(bool new_state);
};


#endif //EVERLASTING_BIRTHDAY_CARD_CANDLE_H
