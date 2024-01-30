#ifndef EVERLASTING_BIRTHDAY_CARD_DISPLAY_H
#define EVERLASTING_BIRTHDAY_CARD_DISPLAY_H

#include "LiquidCrystal_I2C.h"

const uint8_t LCD_ROWS = 2;
const uint8_t LCD_COLS = 16;

void fulfillRowBuffer(char *buffer);

/// Represents a 16x2 LCD display.
class Display : public LiquidCrystal_I2C {
public:
    /// Text which will be scrolled.
    const char *scrolling_text = nullptr;

    Display(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);

    void display(const char *text, uint8_t shift);

    void displayRows(const char *row1, const char *row2);

//    void displayRows(const __FlashStringHelper *row1, const __FlashStringHelper *row2);

    void displayRows_P_F(const char *row1, const __FlashStringHelper *row2);

//    void displayRows_P(const char *row1, const char *row2);

    void displayError(const __FlashStringHelper *message);

    void displayInfo(const __FlashStringHelper *message);

    void initScrolling(const char *text, uint8_t count);

    void handleScrolling(unsigned short first_frame_duration, unsigned short frame_duration);

    void finishScrolling();

    bool isScrolling() const;

    void reset();


private:
    /// Is true when scrolling text, false when not.
    bool is_scrolling = false;


    /// Length of the text being scrolled.
    unsigned short scrolling_text_length = 0;

    /// Target count of scrolling. todo
    uint8_t scrolling_count = 0;

    /// Current number of times text has been scrolled.
    uint8_t scrolling_streak = 0;

    unsigned short frame_start = 0;
    unsigned long next_frame_start_ts = 0;
};

#endif //EVERLASTING_BIRTHDAY_CARD_DISPLAY_H
