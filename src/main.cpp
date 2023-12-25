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
    ARDUINO_STATE_SLEEP,
    ARDUINO_STATE_SETUP_SLEEP,

    // Arduino is counting down until it begins celebrating.
    ARDUINO_STATE_CELEBRATE_COUNTDOWN,
    ARDUINO_STATE_SETUP_CELEBRATE_COUNTDOWN,

    // Arduino is playing the Happy Birthday song, waiting the candle to be blown.
    ARDUINO_STATE_CELEBRATE,
    ARDUINO_STATE_SETUP_CELEBRATE,

    // Arduino is displaying a wish using LCD screen.
    ARDUINO_STATE_WISH,
    ARDUINO_STATE_SETUP_WISH,

    // Arduino is counting down until it goes to a sleep mode
    ARDUINO_STATE_SLEEP_COUNTDOWN,
    ARDUINO_STATE_SETUP_SLEEP_COUNTDOWN,
};

/// Current Arduino state.
ArduinoState ARDUINO_STATE = ARDUINO_STATE_SETUP_CELEBRATE;


/// Index of the current wish to be displayed.
short WISH_INDEX = 0;

unsigned long WISH_START_TS = 0;

// Hardware:
Display LCD(LCD_ADDRESS, 16, 2);
Microphone MICROPHONE(MICROPHONE_PIN);
Buzzer BUZZER(BUZZER_PIN, SONG);
Candle CANDLE(CANDLE_PIN);


void setup_wait() {

}

void loop_wait() {
    // ...

    ARDUINO_STATE = ARDUINO_STATE_SETUP_CELEBRATE_COUNTDOWN;
}

void setup_countdown() {
    BUZZER.init();
    BUZZER.start_ticking(
            CELEBRATE_COUNTDOWN_TICK_INTERVAL,
            CELEBRATE_COUNTDOWN_TICK_DURATION,
            CELEBRATE_COUNTDOWN_TICK_TONE
    );
    ARDUINO_STATE = ARDUINO_STATE_CELEBRATE_COUNTDOWN;
}

void loop_countdown() {
    BUZZER.handle();
    if (BUZZER.tick_streak == CELEBRATE_COUNTDOWN_TICK_COUNT) {
        BUZZER.finish_ticking();
        ARDUINO_STATE = ARDUINO_STATE_SETUP_CELEBRATE;
    }
}

void setup_celebrate() {
    // init hardware:
    MICROPHONE.init();
    LCD.init();
    CANDLE.init();

    // setup hardware:
    BUZZER.start_song();
    CANDLE.set_powered(true);

    LCD.backlight();
    String text = "Ogo, tebe uje " + String(19) + " let...";
    String caption = "Zadui svechky!!!";
    LCD.start_displaying(text, caption, 3000, 550);

    ARDUINO_STATE = ARDUINO_STATE_CELEBRATE;
}

void loop_celebrate() {
    BUZZER.handle(); // play the song
    LCD.handle();

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
            // Go to the ARDUINO_STATE_SETUP_WISH state:
            ARDUINO_STATE = ARDUINO_STATE_SETUP_WISH;
        }
    }
}

void setup_sleep_countdown() {

}

void loop_sleep_countdown() {

}

void setup_wish() {
    LCD.clear();

    String text = "Hello, World! This is a long text for scrolling.";
    String caption = "caption :3";

    LCD.start_displaying(text, caption, WISH_DISPLAY_FIRST_FRAME_DURATION, WISH_DISPLAY_FRAME_DURATION);

    WISH_START_TS = millis();
    ARDUINO_STATE = ARDUINO_STATE_WISH;
}

void loop_wish() {
    unsigned long now = millis();

    LCD.handle();


//    if (now >= WISH_START_TS + WISH_DURATION) { /// if wish duration has passed
//        // ...
//    }
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    switch (ARDUINO_STATE) {
        case ARDUINO_STATE_SETUP_SLEEP:
            setup_wait();
            break;
        case ARDUINO_STATE_SLEEP:
            loop_wait();
            break;

        case ARDUINO_STATE_SETUP_CELEBRATE_COUNTDOWN:
            setup_countdown();
            break;
        case ARDUINO_STATE_CELEBRATE_COUNTDOWN:
            loop_countdown();
            break;

        case ARDUINO_STATE_SETUP_CELEBRATE:
            setup_celebrate();
            break;
        case ARDUINO_STATE_CELEBRATE:
            loop_celebrate();
            break;

        case ARDUINO_STATE_SETUP_SLEEP_COUNTDOWN:
            setup_sleep_countdown();
            break;
        case ARDUINO_STATE_SLEEP_COUNTDOWN:
            loop_sleep_countdown();
            break;

        case ARDUINO_STATE_SETUP_WISH:
            setup_wish();
            break;
        case ARDUINO_STATE_WISH:
            loop_wish();
            break;
    }
}
