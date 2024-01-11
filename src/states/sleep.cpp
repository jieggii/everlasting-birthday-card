#include "Arduino.h"
#include "avr/sleep.h"

#include "pinout.h"

#include "globals/state.h"
#include "globals/hardware.h"

#include "sleep.h"

/// Wakes up the arduino board from sleep mode.
void wake_up_interrupt_handler() {
    sleep_disable();
    detachInterrupt(digitalPinToInterrupt(WAKE_UP_INTERRUPT_PIN));
    Serial.println(F("info: received wake up interrupt"));
}

void sleep_setup() {
    // Reset the alarm 1 in case it fired:
    RTC.clearAlarm(1);

    Serial.println(F("info: jump to SLEEP_LOOP"));
    ARDUINO_STATE = SLEEP_LOOP;
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
            wake_up_interrupt_handler,
            LOW
    );

    Serial.println(F("info: arduino is put into sleep mode"));
    Serial.flush();

    interrupts(); // allow interrupts
    sleep_cpu(); // enter sleep mode

    // --------------------------------------------------------
    // The arduino is now asleep until woken up by an interrupt
    // --------------------------------------------------------

    // Wakes up at this point when WAKE_UP_INTERRUPT_PIN is brought LOW - interrupt routine is run first
    Serial.println(F("info: arduino woke up"));

    // Re-enable ADC if it was previously running
    ADCSRA = prevADCSRA;

//    Serial.println("info: set state to CHECK_MONTH");

    // todo: check month here instead of a separate state.
//    ARDUINO_STATE = STATE_CHECK_MONTH;
}

//void check_month() {
//    DateTime now = RTC.now();
//    if (now.month() == BIRTH_MONTH) {
//        Serial.println("info: current month is a birthday month");
//        Serial.println("info: set state to CELEBRATE_COUNTDOWN_SETUP");
//        STATE = STATE_CELEBRATE_COUNTDOWN_SETUP;
//        return;
//    }
//
//    Serial.println("info: current month is NOT a birthday month");
//    Serial.println("info: set state to SLEEP_SETUP");
//    STATE = STATE_SLEEP_SETUP;
//}
