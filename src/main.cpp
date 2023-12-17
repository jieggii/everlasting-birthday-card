#include <Arduino.h>
#include "pinout.h"
#include "drivers//Buzzer.h"
#include "drivers/Microphone.h"
#include "drivers/Candle.h"

Microphone* MICROPHONE = new Microphone(MICROPHONE_PIN);
Buzzer* BUZZER = new Buzzer(BUZZER_PIN);
Candle* CANDLE = new Candle(CANDLE_PIN);

void setup() {
    Serial.begin(9600);

    // setup inputs:
    MICROPHONE->init();

    // setup outputs:
    CANDLE->init();
    BUZZER->init();
}

void loop() {
    BUZZER->play_happy_birthday_song();
    delay(5000);
}