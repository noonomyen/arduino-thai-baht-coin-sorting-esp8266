#ifndef __LCD_HPP__
#define __LCD_HPP__

#include <Arduino.h>
#include "LiquidCrystal_I2C.h"

extern LiquidCrystal_I2C lcd;

namespace LCD {
    void init();
    void refresh();
    void clear();
    void print(char*);
    void on();
    void off();
    bool is_on();
    void set_1_baht(uint16_t num);
    void set_5_baht(uint16_t num);
    void set_10_baht(uint16_t num);
    void reset();
};

#endif /* __LCD_HPP__ */