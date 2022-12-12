#include "lcd.hpp"
#include "custom_char.hpp"

uint16_t coin_1_baht = 0;
uint16_t coin_5_baht = 0;
uint16_t coin_10_baht = 0;
uint16_t coin_total_baht = 0;

bool lcd_status = 0;
bool request_full_refresh = 1;

void LCD::refresh() {
    coin_total_baht = coin_1_baht + (coin_5_baht * 5) + (coin_10_baht * 10);
    if (coin_total_baht > 9999 || coin_1_baht > 999 || coin_1_baht > 999 || coin_1_baht > 999) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.printf("ERROR...");
        lcd.setCursor(0, 1);
        lcd.printf("Total %d baht", coin_total_baht);
        return;
    };
    char buffer[16] = {
        (char)(coin_1_baht % 1000 / 100) + 48,
        (char)(coin_1_baht % 100 / 10) + 48,
        (char)(coin_1_baht % 10) + 48,
        32,
        (char)(coin_5_baht % 1000 / 100) + 48,
        (char)(coin_5_baht % 100 / 10) + 48,
        (char)(coin_5_baht % 10) + 48,
        32,
        (char)(coin_10_baht % 1000 / 100) + 48,
        (char)(coin_10_baht % 100 / 10) + 48,
        (char)(coin_10_baht % 10) + 48,
        32,
        (char)(coin_total_baht % 10000 / 1000) + 48,
        (char)(coin_total_baht % 1000 / 100) + 48,
        (char)(coin_total_baht % 100 / 10) + 48,
        (char)(coin_total_baht % 10) + 48
    };
    if (buffer[0] == 48) {
        buffer[0] = 32;
        if (buffer[1] == 48) {
            buffer[1] = 32;
        };
    };
    if (buffer[4] == 48) {
        buffer[4] = 32;
        if (buffer[5] == 48) {
            buffer[5] = 32;
        };
    };
    if (buffer[8] == 48) {
        buffer[8] = 32;
        if (buffer[9] == 48) {
            buffer[9] = 32;
        };
    };
    if (buffer[12] == 48) {
        buffer[12] = 32;
        if (buffer[13] == 48) {
            buffer[13] = 32;
            if (buffer[14] == 48) {
                buffer[14] = 32;
            };
        };
    };
    lcd.setCursor(0, 1);
    lcd.printf(buffer);
    if (request_full_refresh) {;
        lcd.setCursor(0, 0);
        lcd.printf("  1   5  10     ");
        lcd.setCursor(13, 0);
        lcd.write(0);
        lcd.setCursor(14, 0);
        lcd.write(1);
        lcd.setCursor(15, 0);
        lcd.write(2);
        request_full_refresh = 0;
    };
};

void LCD::init() {
    lcd.init();
    lcd.clear();
    lcd.backlight();
    lcd.setBacklight(HIGH);
    lcd.createChar(0, custom_char::char_3610);
    lcd.createChar(1, custom_char::char_3634);
    lcd.createChar(2, custom_char::char_3607);
    lcd.setCursor(0, 0);
    lcd_status = 1;
};

void LCD::set_1_baht(uint16_t num) { coin_1_baht = num; };
void LCD::set_5_baht(uint16_t num) { coin_5_baht = num; };
void LCD::set_10_baht(uint16_t num) { coin_10_baht = num; };

void LCD::reset() {
    coin_1_baht = 0;
    coin_5_baht = 0;
    coin_10_baht = 0;
    LCD::refresh();
};

void LCD::off() {
    lcd.setBacklight(LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd_status = 0;
};

void LCD::on() {
    request_full_refresh = 1;
    LCD::refresh();
    lcd.setBacklight(HIGH);
    lcd_status = 1;
};

bool LCD::is_on() {
    return lcd_status;
};

void LCD::print(char *str_) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.printf(str_);
    request_full_refresh = 1;
};

void LCD::print(char *str_0, char *str_1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.printf(str_0);
    lcd.setCursor(0, 1);
    lcd.printf(str_1);
    request_full_refresh = 1;
};

void LCD::clear() {
    lcd.clear();
};
