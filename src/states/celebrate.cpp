#include "settings.h"

#include "globals/hardware.h"
#include "globals/state.h"

#include "celebrate.h"


void celebrate_setup() {
    // Setup hardware:
    BUZZER.startSong(&SONG, SONG_REPEAT);
    CANDLE_LED.turn_on();
    LCD.backlight();

    // Calculate person's age at the moment:
    DateTime now = RTC.now();
    const unsigned int age = now.year() - BIRTH_YEAR;

    // Display the text:
    String text = "OGO, TEBE UJE " + String(age) + " LET!";
    String caption = "Zadui svechku :)";
//    LCD.start_displaying(
//            text,
//            caption,
//            WISH_DISPLAY_FIRST_FRAME_DURATION,
//            WISH_DISPLAY_FRAME_DURATION
//    );

    Serial.println(F("info: jump to CELEBRATE_LOOP"));
    ARDUINO_STATE = ArduinoState::CELEBRATE_LOOP;
}

void celebrate_loop() {
    BUZZER.handle(); // continue playing the song
//    LCD.handle(); // continue displaying the text

    if (CANDLE_LED.isPowered()) { // if candle is still turned on
        bool microphone_triggered = MICROPHONE.isTriggered(
                MICROPHONE_TRIGGER_TRESHOLD, MICROPHONE_TRIGGER_STREAK
        );
        if (microphone_triggered) { // if microphone indicates that candle is blown now
            CANDLE_LED.turn_off(); // turn off the candle
            LCD.finish_displaying(); // finish displaying the text
            BUZZER.finishSong(); // finish playing the song
        }
    } else { // if candle has been blown
        if (BUZZER.getState() == STANDBY &&
            !LCD.displaying) { // if song has already stopped playing and LCD finished displaying the text

            Serial.println(F("info: jump to WISH_SETUP"));
            ARDUINO_STATE = WISH_SETUP;
        }
    }
}