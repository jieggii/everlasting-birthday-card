#include "Display.h"


Display::Display(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows): LiquidCrystal_I2C(lcd_addr, lcd_cols, lcd_rows) {

}