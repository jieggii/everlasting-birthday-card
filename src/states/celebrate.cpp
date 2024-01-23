#include "settings.h"

#include "globals/hardware.h"
#include "globals/state.h"

#include "celebrate.h"


void celebrate_setup() {
    // Setup hardware:
    LCD.backlight();
    CANDLE_LED.turnOn();
    BUILTIN_LED.turnOn();
    LCD.backlight();
    BUZZER.initSong(&SONG, SONG_REPEAT);

    // Calculate person's age at the moment:
    const DateTime now = RTC.now();
    const uint8_t age = now.year() - BIRTH_DATE.year();

    // Initialize scrolling of the congratulation text:
    char buffer[sizeof(CONGRATULATION)]; // note about buffer size: -1 for an extra `%` symbol, +1 to store null-terminator => +0
    snprintf_P(buffer, sizeof(buffer), CONGRATULATION, age);
    LCD.initScrolling(buffer, 10);

    ARDUINO_STATE = ArduinoState::CELEBRATE_LOOP;
}

void celebrate_loop() {
    // play song and scroll congratulation text:
    BUZZER.handle();
    LCD.handleScrolling(LCD_SCROLLING_FIRST_FRAME_DURATION, LCD_SCROLLING_FRAME_DURATION);

    if (CANDLE_LED.isPowered()) { // if candle is still turned on
        bool microphone_triggered = MICROPHONE.isTriggered(
                MICROPHONE_TRIGGER_TRESHOLD, MICROPHONE_TRIGGER_STREAK
        );
        if (microphone_triggered) { // if blowing is detected by the microphone
            // turn of candle, gracefully finish scrolling and playing song:
            CANDLE_LED.turnOff();
            BUILTIN_LED.turnOff();
            LCD.finishScrolling();
            BUZZER.finishSong();
        }
    } else { // if the candle is blown now
        if (BUZZER.getState() == BuzzerState::STANDBY) { // if song has already stopped playing
            LCD.reset();
            ARDUINO_STATE = WISH_SETUP;
        }
    }
}