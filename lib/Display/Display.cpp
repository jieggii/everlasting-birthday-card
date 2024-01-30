#include "Display.h"
#include "Arduino.h"

const char ERROR_LITERAL[] PROGMEM = "ERROR:";
const char INFO_LITERAL[] PROGMEM = "INFO:";

/// Fulfills a buffer with space (' ') characters, ensures proper 0-termination.
/// Note: buffer must be of length LCD_COLS + 1.
/// Example (considering that LCD_COLS is equal to 16):
/// "hello" will be fulfilled to "hello           ".
void fulfillRowBuffer(char *buffer) {
    // find 0-terminator index:
    uint8_t terminator_index = 0;
    for (uint8_t i = 0; i <= LCD_COLS; i++) {
        if (buffer[i] == '\0') {
            terminator_index = i;
            break;
        }
    }
    // fulfill buffer with spaces:
    for (uint8_t i = terminator_index; i < LCD_COLS; i++) {
        Serial.println("set ' ': " + String(i));
        buffer[i] = ' ';
    }
    // add 0-terminator in the end of the buffer
    buffer[LCD_COLS] = '\0';
}

Display::Display(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows) :
        LiquidCrystal_I2C(lcd_addr, lcd_cols, lcd_rows) {
}

/// Displays text of maximal length of 32 characters using first and second row of the LCD.
void Display::display(const char *text, uint8_t shift = 0) {
    char row1[LCD_COLS + 1];
    char row2[LCD_COLS + 1];

    bool met_terminator = false;
    for (uint8_t i = 0; i < LCD_COLS * LCD_ROWS; i++) {
        if (text[i + shift] == '\0') {
            met_terminator = true;
        }

        char symbol;
        if (met_terminator) {
            symbol = ' ';
        } else {
            symbol = text[i + shift];
        }

        if (i < LCD_COLS) {
            row1[i] = symbol;
        } else {
            row2[i - LCD_COLS] = symbol;
        }
    }

    row1[LCD_COLS] = '\0';
    row2[LCD_COLS] = '\0';

    this->displayRows(row1, row2);
}

/// Displays text in both rows separately. Both rows must be strings.
void Display::displayRows(const char *row1, const char *row2) {
    this->setCursor(0, 0);
    this->print(row1);
    this->setCursor(0, 1);
    this->print(row2);
}

/// Displays text in both rows separately. The first row must be a string stored in PROGMEM and the second must be a flash-string
void Display::displayRows_P_F(const char *row1, const __FlashStringHelper *row2) {
    char row1_buffer[strlen_P(row1) + 1];
    strcpy_P(row1_buffer, row1);

    this->setCursor(0, 0);
    this->print(row1_buffer);
    this->setCursor(0, 1);
    this->print(row2);
}

/// Displays an error message.
void Display::displayError(const __FlashStringHelper *message) {
    this->displayRows_P_F(ERROR_LITERAL, message);
}

/// Displays information message stored in PROGMEM.
void Display::displayInfo(const __FlashStringHelper *message) {
    this->displayRows_P_F(INFO_LITERAL, message);
}

/// Sets up scrolling settings, put display into scrolling state.
void Display::initScrolling(const char *text, uint8_t count) {
    this->scrolling_text = text;
    this->scrolling_count = count;

    this->scrolling_text_length = strlen(text);

    this->is_scrolling = true;
    this->next_frame_start_ts = millis();
}

/// Gracefully finishes scrolling text (shows it until the end).
void Display::finishScrolling() {
    this->scrolling_count = 0;
}

/// Returns true if display is in the scrolling state.
bool Display::isScrolling() const {
    return this->is_scrolling;
}

/// Handles scrolling (must be called in a loop).
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

        this->display(this->scrolling_text, this->frame_start);

        if (this->frame_start == this->scrolling_text_length) {
            this->frame_start = 0;
            this->scrolling_streak++;
            if (this->scrolling_streak >= this->scrolling_count) {
                this->reset();
            }
        } else {
            this->frame_start++;
        }
    }
}

/// Resets display to the default state aborting scrolling.
void Display::reset() {
    this->is_scrolling = false;

    this->scrolling_count = 0;
    this->scrolling_streak = 0;

    this->scrolling_text = nullptr;
    this->scrolling_text_length = 0;

    this->frame_start = 0;
    this->next_frame_start_ts = 0;
}
