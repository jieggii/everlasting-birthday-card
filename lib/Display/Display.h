#ifndef EVERLASTING_BIRTHDAY_CARD_DISPLAY_H
#define EVERLASTING_BIRTHDAY_CARD_DISPLAY_H

#include "LiquidCrystal_I2C.h"

class Display : public LiquidCrystal_I2C {
public:
    Display(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);
};


#endif //EVERLASTING_BIRTHDAY_CARD_DISPLAY_H
