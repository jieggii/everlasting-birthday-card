
#ifndef EVERLASTING_BIRTHDAY_CARD_BUZZER_H
#define EVERLASTING_BIRTHDAY_CARD_BUZZER_H

#include "settings.h"


class Buzzer {
public:
    unsigned short pin;

    explicit Buzzer(unsigned short pin);
    void init();
    void draw_attention();
    void play_happy_birthday_song();
};


#endif //EVERLASTING_BIRTHDAY_CARD_BUZZER_H
