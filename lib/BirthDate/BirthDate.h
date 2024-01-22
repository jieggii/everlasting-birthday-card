#ifndef EVERLASTING_BIRTHDAY_CARD_BIRTHDAY_H
#define EVERLASTING_BIRTHDAY_CARD_BIRTHDAY_H

#include "RTClib.h"

class BirthDate : public DateTime {
public:
    BirthDate(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);

    DateTime nextBirthday(const DateTime &now) const;
};

#endif //EVERLASTING_BIRTHDAY_CARD_BIRTHDAY_H
