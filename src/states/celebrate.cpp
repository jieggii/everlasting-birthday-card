#include "settings.h"

#include "globals/hardware.h"
#include "globals/state.h"

#include "celebrate.h"


void celebrate_setup() {
    // Setup hardware:
    BUZZER.beginSong(&SONG, SONG_REPEAT);
    CANDLE_LED.turnOn();
    LCD.backlight();

    // Calculate person's age at the moment:
    DateTime now = RTC.now();
    const unsigned int age = now.year() - BIRTH_DATE.year();

    // Display the text:
    LCD.initScrolling("Test 123 123 123 123 123 123 123 123 123", 255);

    Serial.println(F("info: jump to CELEBRATE_LOOP"));
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
            LCD.finishScrolling(); // finish displaying the text
            BUZZER.finishSong(); // finish playing the song
        }
    } else { // if candle has been blown
        if (BUZZER.getState() == BuzzerState::STANDBY &&
            !LCD.isScrolling()) { // if song has already stopped playing and LCD finished displaying the text

            Serial.println(F("info: jump to WISH_SETUP"));
            ARDUINO_STATE = WISH_SETUP;
        }
    }
}