#include "BirthDate.h"

#include "RTClib.h"


BirthDate::BirthDate(
        uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec
) : DateTime(year, month, day, hour, min, sec) {}

DateTime BirthDate::nextBirthday(const DateTime &now) const {
    const DateTime birthday_this_year = DateTime(
            now.year(), this->month(), this->day(),
            this->hour(), this->minute(), this->second()
    );
    const DateTime birthday_next_year = DateTime(
            now.year() + 1, this->month(), this->day(),
            this->hour(), this->minute(), this->second()
    );
    if (now > birthday_this_year) {
        return birthday_next_year;
    }
    return birthday_this_year;
}

