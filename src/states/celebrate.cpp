#include "settings.h"

#include "globals/hardware.h"
#include "globals/state.h"

#include "celebrate.h"


void celebrate_setup() {
    // Setup hardware:
    CANDLE_LED.turnOn();
    BUILTIN_LED.turnOn();
    LCD.backlight();
    BUZZER.beginSong(&SONG, SONG_REPEAT);

    // Calculate person's age at the moment:
    const DateTime now = RTC.now();
    const uint8_t age = now.year() - BIRTH_DATE.year();

    char text[50]; // todo: calculate desired buffer size instead of setting it manually
    snprintf_P(text, sizeof(text), CELEBRATE_TEXT_FORMAT, age);

    // Scroll the text:
    LCD.initScrolling(text, 10);

    ARDUINO_STATE = ArduinoState::CELEBRATE_LOOP;
}

void celebrate_loop() {
    BUZZER.handle(); // continue playing the song
    LCD.handleScrolling(
            LCD_SCROLLING_FIRST_FRAME_DURATION, LCD_SCROLLING_FRAME_DURATION
    ); // continue displaying the text

    if (CANDLE_LED.isPowered()) { // if candle is still turned on
        bool microphone_triggered = MICROPHONE.isTriggered(
                MICROPHONE_TRIGGER_TRESHOLD, MICROPHONE_TRIGGER_STREAK
        );
        if (microphone_triggered) { // if microphone indicates that candle is blown now
            CANDLE_LED.turnOff(); // turn off the candle
            BUILTIN_LED.turnOff();
            LCD.finishScrolling(); // finish displaying the text
            BUZZER.finishSong(); // finish playing the song
        }
    } else { // if candle has been blown
        if (BUZZER.getState() == BuzzerState::STANDBY &&
            !LCD.isScrolling()) { // if song has already stopped playing and LCD finished displaying the text
            ARDUINO_STATE = WISH_SETUP;
        }
    }
}