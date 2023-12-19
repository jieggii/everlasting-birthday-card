//
// Created by jieggii on 12/15/23.
//

#ifndef EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H
#define EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H


class Microphone {
public:
    explicit Microphone(unsigned short pin, unsigned short trigger_treshold, unsigned short target_trigger_streak);
    void init();
    bool check_trigger();

private:
    unsigned short pin;
    unsigned int target_trigger_streak;
    unsigned int trigger_treshold;

    unsigned trigger_streak = 0;

    int read();
};


#endif //EVERLASTING_BIRTHDAY_CARD_MICROPHONE_H
