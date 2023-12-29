#include "Display.h"
#include "Arduino.h"

Display::Display(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows) :
        LiquidCrystal_I2C(lcd_addr, lcd_cols, lcd_rows) {

}

void Display::start_displaying(String &text, String &caption, short first_frame_duration, short frame_duration) {
    this->text = text;
    for (unsigned short i = 0; i < this->frame_length; i++) {
        this->text = text + " ";
    }
    this->frame_start = 0;
    this->current_frame_is_first = true;

    this->first_frame_duration = first_frame_duration;
    this->frame_duration = frame_duration;
    this->previous_frame_duration = first_frame_duration;

    this->displaying = true;
    this->display_next_time = true;
    this->text_length = text.length();

    this->setCursor(0, 1);
    this->print(caption);
}

void Display::finish_displaying() {
    display_next_time = false;
}

void Display::handle() {
    if (!this->displaying) {
        return;
    }

    unsigned long now = millis();

    if ((this->current_frame_is_first) || (now - this->frame_displayed_ts >= this->previous_frame_duration)) {
        // Stop displaying text if it should not be displayed.
        if (this->current_frame_is_first && !this->display_next_time) {
            this->displaying = false;
            return;
        }

        unsigned short frame_end = this->frame_start + this->frame_length;

        this->setCursor(0, 0);
        this->print(
                this->text.substring(this->frame_start, frame_end)
        );
        this->frame_displayed_ts = now;
        this->frame_start++;

        if (this->current_frame_is_first) {
            this->current_frame_is_first = false;
            this->previous_frame_duration = this->first_frame_duration;
        } else {
            this->previous_frame_duration = this->frame_duration;
        }

        if (this->frame_start == this->text_length + 1) {
            this->frame_start = 0;
            this->current_frame_is_first = true;
        }
    }
}
