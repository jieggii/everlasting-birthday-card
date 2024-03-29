#ifndef EVERLASTING_BIRTHDAY_CARD_STATE_H
#define EVERLASTING_BIRTHDAY_CARD_STATE_H

/// All states of the birthday card.
enum ArduinoState {
    // Diagnostic state: Arduino is testing all hardware and displaying diagnostic information using LCD.
    DIAGNOSTIC_SETUP,
    DIAGNOSTIC_LOOP,

    // Home states: Arduino is displaying time left for the birthday date.
    HOME_SETUP,
    HOME_LOOP,

    // Handle alarm interrupt state: Arduino jumps to COUNTDOWN_SETUP state if the current month matches with the birthday month, otherwise to HOME_SETUP
    HANDLE_ALARM_INTERRUPT,

    // Countdown state: Arduino is counting down until it begins celebrating.
    COUNTDOWN_SETUP,
    COUNTDOWN_LOOP,

    // Celebrate state: Arduino is playing the Happy Birthday song, waiting the candle to be blown.
    CELEBRATE_SETUP,
    CELEBRATE_LOOP,

    // Wish state: Arduino is displaying a wish using LCD screen.
    WISH_LOOP,
    WISH_SETUP,

    // Goodbye state: Arduino says goodbye till the next birthday.
    GOODBYE_SETUP,
    GOODBYE_LOOP,
};

/// Global variable keeping current state of the Arduino board.
extern ArduinoState ARDUINO_STATE;

#endif //EVERLASTING_BIRTHDAY_CARD_STATE_H
