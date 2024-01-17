#include "BirthDate.h"

#include "RTClib.h"


BirthDate::BirthDate(
        uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec
) : DateTime(year, month, day, hour, min, sec) {

}

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

/// Well... I am not sure if it is possible to rewrite this code in
/// a better manner...
//DateTime BirthDate::getNextBirthday(const DateTime &now) const {
//    uint16_t birthday_year;
//
//    if (now.month() > this->month()) {
//        birthday_year = now.year() + 1;
//    } else if (now.month() == this->month()) {
//        if (now.day() > this->day()) {
//            birthday_year = now.year() + 1;
//        } else if (now.day() == this->day()) {
//            if (now.hour() > this->hour()) {
//                birthday_year = now.year() + 1;
//            } else if (now.hour() == this->hour()) {
//                if (now.second() > this->second()) {
//                    birthday_year = now.year() + 1;
//                } else if (now.second() == this->second()) {
//                    birthday_year = now.year();
//                } else {
//                    birthday_year = now.year();
//                }
//            } else {
//                birthday_year = now.year();
//            }
//        } else {
//            birthday_year = now.year();
//        }
//    } else {
//        birthday_year = now.year();
//    }
//
//    return DateTime(
//            birthday_year,
//            this->month(),
//            this->day(),
//            this->hour(),
//            this->minute(),
//            this->second()
//    );
//}
//

