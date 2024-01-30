#ifndef EVERLASTING_BIRTHDAY_CARD_BIRTHDATE_H
#define EVERLASTING_BIRTHDAY_CARD_BIRTHDATE_H

#include "RTClib.h"

/// Represents a date of a person's birth.
class BirthDate : public DateTime {
public:
    BirthDate(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);

    DateTime nextBirthday(const DateTime &now) const;
};

#endif //EVERLASTING_BIRTHDAY_CARD_BIRTHDATE_H
