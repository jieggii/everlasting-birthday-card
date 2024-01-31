#include "settings.h"

#include "globals/hardware.h"
#include "globals/state.h"

#include "celebrate.h"

void celebrate_setup() {
    LCD.backlight();
    CANDLE_LED.turnOn();
    BUZZER.initSong(CELEBRATE_SONG, CELEBRATE_SONG_REPEAT);

    // Calculate person's age at the moment:
    const DateTime now = RTC.now();
    const uint8_t age = now.year() - BIRTH_DATE.year();

    // Initialize scrolling of the congratulation text:
    char buffer[CELEBRATE_TEXT_BUFSIZE];
    snprintf_P(buffer, sizeof(buffer), CELEBRATE_TEXT, age);
    LCD.initScrolling(buffer, 255);

    ARDUINO_STATE = ArduinoState::CELEBRATE_LOOP;
}

void celebrate_loop() {
    // play song and scroll congratulation text:
    BUZZER.handle();

    // scroll the short congratulation:
    LCD.handleScrolling(LCD_SCROLLING_FIRST_FRAME_DURATION, LCD_SCROLLING_FRAME_DURATION);

    if (CANDLE_LED.isPowered()) { // if candle is still turned on
        bool microphone_triggered = MICROPHONE.isTriggered(
                MICROPHONE_TRIGGER_TRESHOLD, MICROPHONE_TRIGGER_STREAK
        );
        if (microphone_triggered) { // if blowing is detected by the microphone
            // turn of candle, gracefully finish scrolling and playing song:
            CANDLE_LED.turnOff();
            LCD.finishScrolling();
            BUZZER.finishSong();
        }
    } else { // if the candle is blown now
        if (BUZZER.getState() == BuzzerState::STANDBY) { // if song has already stopped playing
            LCD.reset();

            delay(1000);
            ARDUINO_STATE = WISH_SETUP;
        }
    }
}