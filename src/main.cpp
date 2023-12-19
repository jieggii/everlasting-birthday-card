#include <Arduino.h>

#include <LiquidCrystal_I2C.h>

#include "pinout.h"
#include "settings.h"
#include "drivers/Buzzer.h"
#include "drivers/Microphone.h"
#include "drivers/Candle.h"
#include "drivers/Display.h"

// All states of the Arduino.
enum CardState {
    // Arduino is waiting for the birthday date (DS3231 alarm interrupt).
    WAIT,
    SETUP_WAIT,

    // Arduino is counting down in order to begin celebrating.
    COUNTDOWN,
    SETUP_COUNTDOWN,

    // Arduino is playing the Happy Birthday song, waiting the candle to be blown.
    CELEBRATE,
    SETUP_CELEBRATE,

    // Arduino displays a wish using LCD screen.
    WISH,
    SETUP_WISH,
};

CardState CARD_STATE = WAIT;
unsigned long START_COUNTDOWN_TS = 0;

// Define hardware:
Display LCD(0x27,  16, 2);
Microphone MICROPHONE(
        MICROPHONE_PIN,
        MICROPHONE_TRIGGER_TRESHOLD,
        MICROPHONE_TRIGGER_STREAK);
Buzzer BUZZER(BUZZER_PIN, SONG);
Candle CANDLE(CANDLE_PIN);

void setup() {
    Serial.begin(9600);

    // setup outputs:
//    CANDLE.init();
//    BUZZER.init();
}

void setup_wait() {

}

void loop_wait() {
    // ...

    CARD_STATE = SETUP_COUNTDOWN;
}

void setup_countdown() {
    BUZZER.init();
    BUZZER.start_ticking(COUNTDOWN_TICK_INTERVAL, COUNTDOWN_TICK_DURATION, COUNTDOWN_TICK_TONE);
    CARD_STATE = COUNTDOWN;
}

void loop_countdown() {
    BUZZER.handle();
    if (BUZZER.tick_streak == COUNTDOWN_TICK_COUNT) {
        BUZZER.finish_ticking();
        CARD_STATE = SETUP_CELEBRATE;
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
    CANDLE.set_state(true);

    CARD_STATE = CELEBRATE;
}

void loop_celebrate() {
    BUZZER.handle();
    bool candle_blown = MICROPHONE.check_trigger();
    if (candle_blown) {
        CANDLE.set_state(false);
        BUZZER.finish_song();
    }
}

//void setup_wish() {
//
//}
//
//void loop_wish() {
//
//}

void loop() {
    switch (CARD_STATE) {
        case SETUP_WAIT:
            setup_wait();
            break;
        case WAIT:
            loop_wait();
            break;

        case SETUP_COUNTDOWN:
            setup_countdown();
            break;
        case COUNTDOWN:
            loop_countdown();
            break;

        case SETUP_CELEBRATE:
            setup_celebrate();
            break;
        case CELEBRATE:
            loop_celebrate();
            break;



//        case WISH_SETUP:
//            setup_wish();
//            break;
//        case WISH:
//            loop_wish();
//            break;
    }
}
