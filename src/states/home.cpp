#include "literals.h"

#include "settings.h"
#include "globals/hardware.h"
#include "globals/state.h"

#include "home.h"

unsigned short HOME_DISPLAY_INTERVAL = 1000;
unsigned long HOME_LAST_DISPLAY_MILLIS = 0;


void home_setup() {
    // initialize random generator:
    randomSeed(analogRead(5));

    // initialize buzzer with a random song:
    uint8_t song_index = random(0, (HOME_SONGS_COUNT));
    const Song *song = HOME_SONGS[song_index];
    BUZZER.initSong(song, 1);

    LCD.backlight();
    ARDUINO_STATE = ArduinoState::HOME_LOOP;
}

void home_loop() {
    BUZZER.handle();

    unsigned long current_millis = millis();
    if (current_millis - HOME_LAST_DISPLAY_MILLIS >= HOME_DISPLAY_INTERVAL) {
        // buffers holding information which will be displayed in the display:
        char row1[LCD_COLS + 1];
        char row2[LCD_COLS + 1];

        const DateTime now = RTC.now();

        if (CONTROL_BUTTON.isPressed()) {
            const float temperature = RTC.getTemperature();
            char temperature_buffer[5];
            dtostrf(temperature, 2, 2, temperature_buffer);

            snprintf_P(
                    row1, sizeof(row1), DATE_FORMAT_LITERAL,
                    now.day(),
                    now.month(),
                    now.year() - 2000,
                    now.hour(),
                    now.minute(),
                    now.second()
            );
            snprintf(row2, sizeof(row2), "temp: %s%cC   ", temperature_buffer, (char) 223);
        } else {
            const DateTime birthday = BIRTH_DATE.nextBirthday(now);
            const TimeSpan time_left = birthday - now;

            snprintf(row1, sizeof(row1), "Do DR: %d dnei,", time_left.days());
            snprintf(
                    row2, sizeof(row2), "    %02d:%02d:%02d    ",
                    time_left.hours(), time_left.minutes(), time_left.seconds()
            );
        }

        fulfillRowBuffer(row1);
        fulfillRowBuffer(row2);
        LCD.displayRows(row1, row2);

        HOME_LAST_DISPLAY_MILLIS = current_millis;
    }
}
