#include <Arduino.h>

#include "pinout.h"
#include "settings.h"
#include "../lib/Buzzer/Buzzer.h"
#include "../lib/Microphone/Microphone.h"
#include "../lib/Candle/Candle.h"
#include "../lib/Display/Display.h"


// All states of the birthday card.
enum ArduinoState {
    // Arduino is waiting for the birthday date (DS3231 alarm interrupt).
    SLEEP,
    SETUP_SLEEP,

    // Arduino is counting down until it begins celebrating.
    CELEBRATE_COUNTDOWN,
    SETUP_CELEBRATE_COUNTDOWN,

    // Arduino is playing the Happy Birthday song, waiting the candle to be blown.
    CELEBRATE,
    SETUP_CELEBRATE,

    // Arduino is displaying a wish using LCD screen.
    WISH,
    SETUP_WISH,

    // Arduino is counting down until it goes to a sleep mode
    SLEEP_COUNTDOWN,
    SETUP_SLEEP_COUNTDOWN,
};

ArduinoState ARDUINO_STATE = SLEEP;
unsigned long WISH_START_TS = 0;

// Define hardware:
Display LCD(0x27, 16, 2);
Microphone MICROPHONE(MICROPHONE_PIN);
Buzzer BUZZER(BUZZER_PIN, SONG);
Candle CANDLE(CANDLE_PIN);


void setup_wait() {

}

void loop_wait() {
    // ...

    ARDUINO_STATE = SETUP_CELEBRATE_COUNTDOWN;
}

void setup_countdown() {
    BUZZER.init();
    BUZZER.start_ticking(
            CELEBRATE_COUNTDOWN_TICK_INTERVAL,
            CELEBRATE_COUNTDOWN_TICK_DURATION,
            CELEBRATE_COUNTDOWN_TICK_TONE
    );
    ARDUINO_STATE = CELEBRATE_COUNTDOWN;
}

void loop_countdown() {
    BUZZER.handle();
    if (BUZZER.tick_streak == CELEBRATE_COUNTDOWN_TICK_COUNT) {
        BUZZER.finish_ticking();
        ARDUINO_STATE = SETUP_CELEBRATE;
    }
}

void setup_celebrate() {
    // init hardware:
    MICROPHONE.init();
    LCD.init();
    CANDLE.init();

    // setup hardware:
    LCD.backlight();
    LCD.print("Happy birthday!");
    LCD.setCursor(0, 1);
    LCD.print("Blow the candle!");

    BUZZER.start_song();
    CANDLE.set_powered(true);

    ARDUINO_STATE = CELEBRATE;
}

void loop_celebrate() {
    BUZZER.handle(); // play the song

    if (CANDLE.powered) { // if candle is not blown yet
        bool microphone_triggered = MICROPHONE.is_triggered(
                MICROPHONE_TRIGGER_TRESHOLD, MICROPHONE_TRIGGER_STREAK
        );
        if (microphone_triggered) {
            CANDLE.set_powered(false);
            BUZZER.finish_song();
        }
    } else { // If candle is already blown
        if (BUZZER.state == BUZZER_STATE_STANDBY) { // if song has already stopped playing
            // Go to the SETUP_WISH state:
            ARDUINO_STATE = SETUP_WISH;
        }
    }
}

void setup_sleep_countdown() {

}

void loop_sleep_countdown() {

}

void setup_wish() {
    LCD.clear();
    // todo: scroll text
    LCD.print("Some wish!");

    WISH_START_TS = millis();
    ARDUINO_STATE = WISH;
}

void loop_wish() {
    unsigned long now = millis();

    if (now >= WISH_START_TS + WISH_DURATION) { /// if wish duration has passed
        // ...
    }
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    switch (ARDUINO_STATE) {
        case SETUP_SLEEP:
            setup_wait();
            break;
        case SLEEP:
            loop_wait();
            break;

        case SETUP_CELEBRATE_COUNTDOWN:
            setup_countdown();
            break;
        case CELEBRATE_COUNTDOWN:
            loop_countdown();
            break;

        case SETUP_CELEBRATE:
            setup_celebrate();
            break;
        case CELEBRATE:
            loop_celebrate();
            break;

        case SETUP_SLEEP_COUNTDOWN:
            setup_sleep_countdown();
            break;
        case SLEEP_COUNTDOWN:
            loop_sleep_countdown();
            break;

        case SETUP_WISH:
            setup_wish();
            break;
        case WISH:
            loop_wish();
            break;
    }
}
