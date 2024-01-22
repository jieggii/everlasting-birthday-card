#include "Display.h"
#include "Arduino.h"

Display::Display(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows) :
        LiquidCrystal_I2C(lcd_addr, lcd_cols, lcd_rows) {
}

/// Displays text of max length 32 using first and second row of the LCD.
void Display::display(const char *text, uint8_t shift = 0) {
    char row1_buffer[DISPLAY_COLS + 1];
    char row2_buffer[DISPLAY_COLS + 1];

    bool met_terminator = false;
    for (unsigned short i = 0; i < DISPLAY_COLS * DISPLAY_ROWS; i++) {
        if (text[i + shift] == '\0') {
            met_terminator = true;
        }

        char symbol;
        if (met_terminator) {
            symbol = ' ';
        } else {
            symbol = text[i + shift];
        }

        if (i < DISPLAY_COLS) {
            row1_buffer[i] = symbol;
        } else {
            row2_buffer[i - DISPLAY_COLS] = symbol;
        }
    }

    row1_buffer[DISPLAY_COLS] = '\0';
    row2_buffer[DISPLAY_COLS] = '\0';

    this->displayRows(row1_buffer, row2_buffer);
}

void Display::displayRows(const char *row1, const char *row2) {
    this->setCursor(0, 0);
    this->print(row1);
    this->setCursor(0, 1);
    this->print(row2);
}

//void Display::displayRows(const __FlashStringHelper *row1, const __FlashStringHelper *row2) {
//    this->setCursor(0, 0);
//    this->print(row1);
//    this->setCursor(0, 1);
//    this->print(row2);
//}

void Display::displayRows_P(const char *row1, const char *row2) {
    char row1_buffer[strlen_P(row1) + 1];
    char row2_buffer[strlen_P(row2) + 1];
    strcpy_P(row1_buffer, row1);
    strcpy_P(row2_buffer, row2);

    this->displayRows(row1_buffer, row2_buffer);
}

void Display::displayError_P(const char *message) {
    this->displayRows_P(ERROR_LITERAL, message);
}

void Display::displayInfo_P(const char *message) {
    this->displayRows(INFO_LITERAL, message);
}

void Display::initScrolling(const char *text, uint8_t count) {
    this->scrolling_text = text;
    this->scrolling_count = count;

    this->scrolling_text_length = strlen(text);

    this->is_scrolling = true;
    this->next_frame_start_ts = millis();
}

void Display::finishScrolling() {
    this->scrolling_count = 0;
}

bool Display::isScrolling() const {
    return this->is_scrolling;
}

void Display::handleScrolling(unsigned short first_frame_duration, unsigned short frame_duration) {
    if (!this->isScrolling()) {
        return;
    }
    unsigned long now = millis();

    if (now >= this->next_frame_start_ts) {
        if (this->frame_start == 0) {
            this->next_frame_start_ts = now + first_frame_duration;
        } else {
            this->next_frame_start_ts = now + frame_duration;
        }

        this->clear(); // todo: try toggling (when wish is displaying)
        this->display(this->scrolling_text, this->frame_start);

        if (this->frame_start == this->scrolling_text_length) {
            this->frame_start = 0;
            this->scrolling_streak++;
            if (this->scrolling_streak >= this->scrolling_count) {
                this->is_scrolling = false;
            }
        } else {
            this->frame_start++;
        }
    }
}





