#include "settings.h"

#include "songs/undertale_start_menu.h"
#include "globals/hardware.h"
#include "globals/state.h"

#include "home.h"


void home_setup() {
    LCD.backlight();
    BUZZER.initSong(&UNDERTALE_START_MENU_SONG, 255);
    ARDUINO_STATE = ArduinoState::HOME_LOOP;
}

// todo: song and temperature
void home_loop() {
    BUZZER.handle();

    const DateTime now = RTC.now();
    const DateTime birthday = BIRTH_DATE.nextBirthday(now);
    const TimeSpan time_left = birthday - now;
    float temperature = RTC.getTemperature();

    // buffers holding information which will be displayed in the display:
    char row1[16 + 1];
    char row2[16 + 1];

    sprintf(row1, "Do DR: %d dnei,", time_left.days());
    sprintf(row2, "    %02d:%02d:%02d    ", time_left.hours(), time_left.minutes(), time_left.seconds());
    LCD.displayRows(row1, row2);
    RTC.getTemperature();
//    BUZZER.tone(220);
//    delay(25);
//    delay(975);
}
