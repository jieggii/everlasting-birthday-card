#include <Arduino.h>
#include "avr/sleep.h"
#include "avr/power.h" // todo remove?
#include "EEPROM.h"

#include "SPI.h" // todo remove?
#include "Wire.h"
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

    // Debug state.
    STATE_DEBUG_SETUP,
    STATE_DEBUG_LOOP,

    /// State which checks month.
    STATE_CHECK_MONTH,

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

/// Time when current wish started displaying.
unsigned long WISH_START_TS = 0;

// Hardware:
/// The lcd display.
Display LCD(LCD_ADDRESS, 16, 2);

/// The microphone which is used to detect candle blowing.
Microphone MICROPHONE(MICROPHONE_PIN);

/// Buzzer which is used to play ticking sound and the song.
Buzzer BUZZER(BUZZER_PIN, SONG);

/// Candle is a simple LED.
Candle CANDLE(CANDLE_LED_PIN);

/// Real time clock module.
RTC_DS3231 RTC;

void wake_up_ISR() {
    sleep_disable();
    detachInterrupt(digitalPinToInterrupt(WAKE_UP_INTERRUPT_PIN));
    Serial.println("info: received wake up interrupt");
}

void sleep_setup() {
    // Reset the alarm 1 in case it fired:
    RTC.clearAlarm(1);

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
            digitalPinToInterrupt(WAKE_UP_INTERRUPT_PIN),
            wake_up_ISR,
            LOW
    );

    Serial.println("info: arduino is going to sleep mode");
    Serial.flush();

    interrupts(); // allow interrupts
    sleep_cpu(); // enter sleep mode

    // --------------------------------------------------------
    // The arduino is now asleep until woken up by an interrupt
    // --------------------------------------------------------

    // Wakes up at this point when WAKE_UP_INTERRUPT_PIN is brought LOW - interrupt routine is run first
    Serial.println("info: arduino woke up by alarm interrupt");

    // Re-enable ADC if it was previously running
    ADCSRA = prevADCSRA;

    Serial.println("info: set state to CHECK_MONTH");
    STATE = STATE_CHECK_MONTH;
}

void debug_setup() {
    LCD.backlight(); // enable screen backlight
    CANDLE.turn_on(); // turn on the candle to test it

    digitalWrite(CANDLE_LED_PIN, HIGH); // turn on the candle pin to test it
    digitalWrite(FAILURE_LED_PIN, HIGH); // turn on the failure pin to test it
    tone(BUZZER_PIN, 443);

    delay(100);

    digitalWrite(FAILURE_LED_PIN, LOW);
    digitalWrite(CANDLE_LED_PIN, LOW);
    noTone(BUZZER_PIN);

    Serial.println("info: set state to DEBUG_LOOP");
    STATE = STATE_DEBUG_LOOP;
}

void debug_loop() {
    // todo: also test buzzer
    DateTime now = RTC.now();
    DateTime alarm = RTC.getAlarm1();

    LCD.clear();
    LCD.print(
            String(now.month()) + "." +
            String(now.day()) + "." +
            String(now.year() - 2000) + " " +
            String(now.hour()) + ":" +
            String(now.minute()) + ":" +
            String(now.second())
    );

    LCD.setCursor(0, 1);
    LCD.print(
            "xx." + String(alarm.day()) +
            ".xx " + String(alarm.hour()) +
            ":" + String(alarm.minute()) +
            ":" + String(alarm.second())
    );


    delay(5000);

//    LCD.clear();
//    LCD.print("Next wish: #" + String(EEPROM.read(WISH_INDEX_EEPROM_ADDRESS)) + " ");

//    delay(1000);
}

/// Checks current month. Sets state to CELEBRATE_COUNTDOWN_SETUP if current month matches with the birthday month.
/// Otherwise sets state to SLEEP_SETUP.
/// This state is needed because it seems that there is no annual alarm support in DS3231.
/// TODO: investigate about annual interrupts and implement them if possible instead of this crap...
void check_month() {
    DateTime now = RTC.now();
    if (now.month() == BIRTH_MONTH) {
        Serial.println("info: current month is a birthday month");
        Serial.println("info: set state to CELEBRATE_COUNTDOWN_SETUP");
        STATE = STATE_CELEBRATE_COUNTDOWN_SETUP;
        return;
    }

    Serial.println("info: current month is NOT a birthday month");
    Serial.println("info: set state to SLEEP_SETUP");
    STATE = STATE_SLEEP_SETUP;
}

void celebrate_countdown_setup() {
    BUZZER.start_ticking(
            CELEBRATE_COUNTDOWN_TICK_INTERVAL,
            CELEBRATE_COUNTDOWN_TICK_DURATION,
            CELEBRATE_COUNTDOWN_TICK_TONE
    );

    Serial.println("info: set state COUNTDOWN_LOOP");
    STATE = STATE_CELEBRATE_COUNTDOWN_LOOP;
}

void celebrate_countdown_loop() {
    BUZZER.handle();
    if (BUZZER.tick_streak == CELEBRATE_COUNTDOWN_TICK_COUNT) {
        BUZZER.finish_ticking();

        Serial.println("info: set state to CELEBRATE_SETUP");
        STATE = STATE_CELEBRATE_SETUP;
    }
}

void celebrate_setup() {
    // setup hardware:
    BUZZER.start_song();
    CANDLE.turn_on();

    LCD.backlight();

    // Calculate person's age today:
    DateTime now = RTC.now();
    const unsigned int age = now.year() - BIRTH_YEAR;

    // Display the text:
    String text = "OGO, TEBE UJE " + String(age) + " LET!";
    String caption = "Zadui svechku :)";
    LCD.start_displaying(
            text,
            caption,
            WISH_DISPLAY_FIRST_FRAME_DURATION,
            WISH_DISPLAY_FRAME_DURATION
    );

    Serial.println("info: set state to CELEBRATE_LOOP");
    STATE = STATE_CELEBRATE_LOOP;
}

void celebrate_loop() {
    BUZZER.handle(); // continue playing the song
    LCD.handle(); // continue displaying the text

    if (CANDLE.powered) { // if candle is still turned on
        bool microphone_triggered = MICROPHONE.is_triggered(
                MICROPHONE_TRIGGER_TRESHOLD, MICROPHONE_TRIGGER_STREAK
        );
        if (microphone_triggered) { // if microphone indicates that candle is blown now
            CANDLE.turn_off(); // turn off the candle
            LCD.finish_displaying(); // finish displaying the text
            BUZZER.finish_song(); // finish playing the song
        }
    } else { // if candle has been blown
        if (BUZZER.state == BUZZER_STATE_STANDBY &&
            !LCD.displaying) { // if song has already stopped playing and LCD finished displaying the text

            Serial.println("info: set state to WISH_SETUP");
            STATE = STATE_WISH_SETUP;
        }
    }
}

void wish_setup() {
    // todo: fix wish index increment and handling logging
//    uint8_t wishIndex = EEPROM.read(WISH_INDEX_EEPROM_ADDRESS);
//    if (wishIndex > WISH_COUNT - 1) {
//        wishIndex = static_cast<uint8_t>(0);
//        Serial.println("warning: resetting current wish index as the stored one is out of range");
//    }
    const short wishIndex = 0; // todo
    Serial.println("info: wish with index " + String(wishIndex) + " will be displayed");

    // Display the current wish:
    LCD.start_displaying(
            WISH_LIST[wishIndex],
            WISH_CAPTION,
            WISH_DISPLAY_FIRST_FRAME_DURATION,
            WISH_DISPLAY_FRAME_DURATION
    );

    // Update stored wish index for the next wish to be displayed next time:
//    uint8_t nextWishIndex = wishIndex + 1;
//    if (nextWishIndex > WISH_COUNT - 1) {
//        nextWishIndex = 0;
//        Serial.println("warning: resetting stored wish index as the stored");
//    }
//    EEPROM.write(WISH_INDEX_EEPROM_ADDRESS, nextWishIndex);

    WISH_START_TS = millis();

    Serial.println("info: set state to WISH_LOOP");
    STATE = STATE_WISH_LOOP;
}

void wish_loop() {
    LCD.handle(); // continue displaying the current wish
    if (millis() - WISH_START_TS >= WISH_DURATION) { // if wish duration has expired
        Serial.println("info: set state to SLEEP_COUNTDOWN_SETUP");
        STATE = STATE_SLEEP_COUNTDOWN_SETUP;
    }
}


void sleep_countdown_setup() {
    LCD.handle(); // continue displaying the current wish
    BUZZER.start_ticking(
            SLEEP_COUNTDOWN_TICK_INTERVAL,
            SLEEP_COUNTDOWN_TICK_DURATION,
            SLEEP_COUNTDOWN_TICK_TONE
    );

    Serial.println("info: set state STATE_SLEEP_COUNTDOWN_LOOP");
    STATE = STATE_SLEEP_COUNTDOWN_LOOP;
}

void sleep_countdown_loop() {
    LCD.handle(); // continue displaying the current wish
    BUZZER.handle(); // make ticking sound using buzzer

    if (BUZZER.tick_streak == SLEEP_COUNTDOWN_TICK_COUNT) {
        LCD.finish_displaying(); // do not display the wish next time again
    }

    if (!LCD.displaying) { // if finished displaying the current wish
        BUZZER.finish_ticking(); // stop making ticking sound

        // disable the LCD:
        LCD.noBacklight();

        Serial.println("info: set state to SLEEP_SETUP");
        STATE = STATE_SLEEP_SETUP;
    }
}

void setup() {
    Serial.begin(9600);

    // Set up input pins:
    pinMode(WAKE_UP_INTERRUPT_PIN, INPUT_PULLUP); // wake up interrupt pin
    MICROPHONE.init_pin(); // microphone pin
    pinMode(DEBUG_BUTTON_PIN, INPUT); // debug button pin

    // Set up output pins:
    pinMode(FAILURE_LED_PIN, OUTPUT); // failure LED
    LCD.init(); // display
    BUZZER.init_pin(); // buzzer pin
    CANDLE.init_pin(); // candle LED pin

    // Disable LCD backlight:
    LCD.noBacklight();

    // Wait for 1,5 seconds:
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2500);
    digitalWrite(LED_BUILTIN, LOW);

    // Initialize RTC:
    if (!RTC.begin()) {
        Serial.println("fatal error: no RTC found");
        digitalWrite(FAILURE_LED_PIN, HIGH);
        while (true);
    }

    // Set current date and time if DS3231 stopped due to power loss:
    if (RTC.lostPower()) {
        RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
        Serial.println("warning: set date and time from compilation time as rtc lost power");
    }

    RTC.disable32K(); // disable 32K pin as it is not needed
    RTC.writeSqwPinMode(DS3231_OFF); // disable square wave generation on SQW pin as it is not needed

    // Reset all alarms:
    RTC.clearAlarm(1);
    RTC.clearAlarm(2);

    RTC.disableAlarm(2); // disable alarm 2 as only alarm 1 will be used

    // Set up an alarm
    DateTime alarmDate(
            2000, // year does not make any sense for the DS3231_A1_Date alarm mode, so let it be 2000 (the default one)
            5, // month does not make any sense for the DS3231_A1_Date alarm mode
            BIRTH_DAY,
            BIRTH_HOUR,
            BIRTH_MINUTE,
            BIRTH_SECOND
    );

    bool success = RTC.setAlarm1(alarmDate, DS3231_A1_Date);
    if (!success) {
        digitalWrite(FAILURE_LED_PIN, HIGH);
        Serial.println("fatal error: failed to set a new alarm");
        while (true);
    }
    Serial.println("info: set new alarm to " + String(alarmDate.timestamp()));

    // Reset index of the current wish to 0 if needed:
    if (WISH_INDEX_RESET) {
        EEPROM.write(WISH_INDEX_EEPROM_ADDRESS, 0); // todo: static cast
    }

    if (digitalRead(DEBUG_BUTTON_PIN) == 1) { // if debug button is pressed
        Serial.println("info: set state to DEBUG_SETUP");
        STATE = STATE_DEBUG_SETUP;
    } else {
        Serial.println("info: set state to SLEEP_SETUP");
        STATE = STATE_SLEEP_SETUP;
    }
}

void loop() {
    switch (STATE) {
        case STATE_SLEEP_SETUP:
            sleep_setup();
            break;
        case STATE_SLEEP_LOOP:
            sleep_loop();
            break;

        case STATE_DEBUG_SETUP:
            debug_setup();
            break;
        case STATE_DEBUG_LOOP:
            debug_loop();
            break;

        case STATE_CHECK_MONTH:
            check_month();
            break;

        case STATE_CELEBRATE_COUNTDOWN_SETUP:
            celebrate_countdown_setup();
            break;
        case STATE_CELEBRATE_COUNTDOWN_LOOP:
            celebrate_countdown_loop();
            break;

        case STATE_CELEBRATE_SETUP:
            celebrate_setup();
            break;
        case STATE_CELEBRATE_LOOP:
            celebrate_loop();
            break;

        case STATE_WISH_SETUP:
            wish_setup();
            break;
        case STATE_WISH_LOOP:
            wish_loop();
            break;

        case STATE_SLEEP_COUNTDOWN_SETUP:
            sleep_countdown_setup();
            break;
        case STATE_SLEEP_COUNTDOWN_LOOP:
            sleep_countdown_loop();
            break;
    }
}
