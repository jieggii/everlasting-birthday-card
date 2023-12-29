#include <Arduino.h>
#include "avr/sleep.h"
#include "avr/power.h" // todo remove?

#include "SPI.h" // todo remove?
#include "RTClib.h"

#include "../lib/Buzzer/Buzzer.h"
#include "../lib/Microphone/Microphone.h"
#include "../lib/Candle/Candle.h"
#include "../lib/Display/Display.h"

#include "pinout.h"
#include "settings.h"


// All states of the birthday card.
enum State {
    // Arduino is waiting for the birthday date (DS3231 alarm interrupt).
    STATE_SLEEP_LOOP,
    STATE_SLEEP_SETUP,

    // Arduino is counting down until it begins celebrating.
    STATE_CELEBRATE_COUNTDOWN_LOOP,
    STATE_CELEBRATE_COUNTDOWN_SETUP,

    // Arduino is playing the Happy Birthday song, waiting the candle to be blown.
    STATE_CELEBRATE_LOOP,
    STATE_CELEBRATE_SETUP,

    // Arduino is displaying a wish using LCD screen.
    STATE_WISH_LOOP,
    STATE_WISH_SETUP,

    // Arduino is counting down until it goes to a sleep mode
    STATE_SLEEP_COUNTDOWN_LOOP,
    STATE_SLEEP_COUNTDOWN_SETUP,
};

/// Current Arduino state.
State STATE;

/// Index of the current wish to be displayed.
short WISH_INDEX = 0;

unsigned long WISH_START_TS = 0;

// Hardware:
Display LCD(LCD_ADDRESS, 16, 2);
Microphone MICROPHONE(MICROPHONE_PIN);
Buzzer BUZZER(BUZZER_PIN, SONG);
Candle CANDLE(CANDLE_PIN);
RTC_DS3231 RTC;


void wake_up_ISR() {
    sleep_disable();
    detachInterrupt(digitalPinToInterrupt(WAKE_UP_INTERRUPT_PIN));
    Serial.println("info: received wake up interrupt");
}

void sleep_setup() {
    // Set up RTC:
    RTC.clearAlarm(1);
    RTC.clearAlarm(2);

    RTC.writeSqwPinMode(DS3231_OFF); // todo: move to setup

    RTC.disableAlarm(2);

    DateTime now = RTC.now();
//    DateTime alarmAt = DateTime(now.year(), 12, 28, 1, 13);
    DateTime alarmAt = now + TimeSpan(10);

    if (RTC.setAlarm1(alarmAt, DS3231_A1_Date)) {
        Serial.println(
                "info: current date is " + String(alarmAt.timestamp()) + ", set wake up alarm to " +
                String(alarmAt.timestamp())
        );
    } else {
        Serial.println("error: could not set alarm");
    }

    Serial.println("info: set state to SLEEP_LOOP");
    STATE = STATE_SLEEP_LOOP;
}

void sleep_loop() {
    static byte prevADCSRA = ADCSRA;
    ADCSRA = 0;
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();

    // Ensure we can wake up again by first disabling interrupts (temporarily) so
    // the wakeISR does not run before we are asleep and then prevent interrupts,
    // and then defining the ISR (Interrupt Service Routine) to run when poked awake
    noInterrupts();
    attachInterrupt(
            digitalPinToInterrupt(WAKE_UP_INTERRUPT_PIN), wake_up_ISR, LOW
    );

    // Send a message just to show we are about to sleep:
    Serial.println("info: arduino put into power down mode");
    Serial.flush();

    // Allow interrupts now
    interrupts();

    // And enter sleep mode as set above
    sleep_cpu();

    // --------------------------------------------------------
    // µController is now asleep until woken up by an interrupt
    // --------------------------------------------------------

    // Wakes up at this point when wakePin is brought LOW - interrupt routine is run first
    Serial.println("info: arduino woke up by alarm interrupt");

    // Re-enable ADC if it was previously running
    ADCSRA = prevADCSRA;

    Serial.println("info: set state to COUNTDOWN_SETUP");
    STATE = STATE_CELEBRATE_COUNTDOWN_SETUP;
}

void countdown_setup() {
    BUZZER.start_ticking(
            CELEBRATE_COUNTDOWN_TICK_INTERVAL,
            CELEBRATE_COUNTDOWN_TICK_DURATION,
            CELEBRATE_COUNTDOWN_TICK_TONE
    );

    Serial.println("info: set state COUNTDOWN_LOOP");
    STATE = STATE_CELEBRATE_COUNTDOWN_LOOP;
}

void countdown_loop() {
    BUZZER.handle();
    if (BUZZER.tick_streak == CELEBRATE_COUNTDOWN_TICK_COUNT) {
        BUZZER.finish_ticking();

        Serial.println("info: set state to CELEBRATE_SETUP");
        STATE = STATE_CELEBRATE_SETUP;
    }
}

void celebrate_setup() {
    // init hardware:

    // setup hardware:
    BUZZER.start_song();
    CANDLE.turn_on();

    LCD.backlight();
    String text = "Ogo, tebe uje " + String(19) + " let...";
    String caption = "Zadui svechky!!!";
    LCD.start_displaying(text, caption, 3000, 550);

    STATE = STATE_CELEBRATE_LOOP;
}

void celebrate_loop() {
    BUZZER.handle(); // play the song
    LCD.handle();

    if (CANDLE.powered) { // if candle is not blown yet
        bool microphone_triggered = MICROPHONE.is_triggered(
                MICROPHONE_TRIGGER_TRESHOLD, MICROPHONE_TRIGGER_STREAK
        );
        if (microphone_triggered) {
            CANDLE.turn_off();
            BUZZER.finish_song();
        }
    } else { // If candle is already blown
        if (BUZZER.state == BUZZER_STATE_STANDBY) { // if song has already stopped playing
            // Go to the ARDUINO_STATE_SETUP_WISH state:
            STATE = STATE_WISH_SETUP;
        }
    }
}

void wish_setup() {
    LCD.clear();

    String caption = "caption :3";

    LCD.start_displaying(
            WISHES[WISH_INDEX], caption, WISH_DISPLAY_FIRST_FRAME_DURATION, WISH_DISPLAY_FRAME_DURATION
    );

    WISH_START_TS = millis();
    STATE = STATE_WISH_LOOP;
}

void wish_loop() {
    LCD.handle();

    if (millis() - WISH_DURATION >= WISH_START_TS) { // if wish duration has passed
        Serial.println("info: set state to SLEEP_COUNTDOWN_SETUP");
        STATE = STATE_SLEEP_COUNTDOWN_SETUP;
//        LCD.finish_displaying(); // gracefully stop displaying wish
    }


}


void sleep_countdown_setup() {
    BUZZER.start_ticking(
            SLEEP_COUNTDOWN_TICK_INTERVAL,
            SLEEP_COUNTDOWN_TICK_DURATION,
            SLEEP_COUNTDOWN_TICK_TONE
    );

    Serial.println("info: set state CELEBRATE_COUNTDOWN_LOOP");
    STATE = STATE_SLEEP_COUNTDOWN_LOOP;
}

void sleep_countdown_loop() {
    LCD.handle();
    BUZZER.handle();

    if (BUZZER.tick_streak == SLEEP_COUNTDOWN_TICK_COUNT) {
        LCD.finish_displaying(); // do not display the text next time
    }

    if (!LCD.displaying) { // if finished displaying the current wish
        BUZZER.finish_ticking(); // disable buzzer

        // disable LCD:
        LCD.noBacklight();
        LCD.clear();

        Serial.println("info: set state to STATE_SLEEP_SETUP");
        STATE = STATE_SLEEP_COUNTDOWN_SETUP;
    }
}

void setup() {
    Serial.begin(9600);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(5000);
    digitalWrite(LED_BUILTIN, LOW);

    // Input pins:
    pinMode(WAKE_UP_INTERRUPT_PIN, INPUT_PULLUP);
    pinMode(MICROPHONE_PIN, INPUT);
    MICROPHONE.init_pin();

    // Output pins:
    pinMode(CANDLE_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    BUZZER.init_pin();
    LCD.init();
    CANDLE.init_pin();

    // Initialize RTC:
    if (!RTC.begin()) {
        while (true) {
            Serial.println("error: couldn't find RTC!");
            delay(300);
        };
    }

    if (RTC.lostPower()) {
        Serial.println("info: set date and time");
        RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

    RTC.disable32K();

    Serial.println("info: set state to SLEEP_SETUP");
    STATE = STATE_SLEEP_SETUP;
}

void loop() {
    switch (STATE) {
        case STATE_SLEEP_SETUP:
            sleep_setup();
            break;
        case STATE_SLEEP_LOOP:
            sleep_loop();
            break;

        case STATE_CELEBRATE_COUNTDOWN_SETUP:
            countdown_setup();
            break;
        case STATE_CELEBRATE_COUNTDOWN_LOOP:
            countdown_loop();
            break;

        case STATE_CELEBRATE_SETUP:
            celebrate_setup();
            break;
        case STATE_CELEBRATE_LOOP:
            celebrate_loop();
            break;

        case STATE_SLEEP_COUNTDOWN_SETUP:
            sleep_countdown_setup();
            break;
        case STATE_SLEEP_COUNTDOWN_LOOP:
            sleep_countdown_loop();
            break;

        case STATE_WISH_SETUP:
            wish_setup();
            break;
        case STATE_WISH_LOOP:
            wish_loop();
            break;
    }
}
