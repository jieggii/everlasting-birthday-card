//
// Created by jieggii on 12/15/23.
//

#ifndef EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H
#define EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H


class Microphone {
public:
    unsigned short pin;

    explicit Microphone(unsigned short pin);
    void init();
    int read();
};


#endif //EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H
