#ifndef EVERLASTING_BIRTHDAY_CARD_DISPLAY_H
#define EVERLASTING_BIRTHDAY_CARD_DISPLAY_H

#include "LiquidCrystal_I2C.h"

class Display : public LiquidCrystal_I2C {
public:
    /// Is true when displaying text, false when not.
    bool displaying = false;

    Display(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);

    void start_displaying(String &text, String &caption, short first_frame_duration, short frame_duration);

    void finish_displaying();

    void handle();

private:
    /// Indicates whether text will be displayed one more time or not.
    bool display_next_time = false;

    /// Is true when we are at the first frame.
    bool current_frame_is_first = false;

    /// Long text which will be displayed and scrolled on the LCD screen.
    String text;

    /// Length of the text being displayed.
    unsigned int text_length;

    /// Duration of a text frame being displayed while scrolling.
    short frame_duration;

    /// Duration of a first text frame being displayed while scrolling.
    short first_frame_duration;

    /// Duration of the previous frame.
    unsigned short previous_frame_duration;

    /// Timestamp when the current frame was displayed.
    unsigned long frame_displayed_ts = 0;

    /// Index of the frame beginning in the text.
    unsigned short frame_start = 0;

    /// Frame length
    const unsigned short frame_length = 16;
};

#endif //EVERLASTING_BIRTHDAY_CARD_DISPLAY_H
