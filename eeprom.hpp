#ifndef __EEPROM_HPP__
#define __EEPROM_HPP__

#include <Arduino.h>
#include <EEPROM.h>

namespace MEM {
    void write_1_baht(uint16_t num);
    void write_5_baht(uint16_t num);
    void write_10_baht(uint16_t num);
    uint16_t read_1_baht();
    uint16_t read_5_baht();
    uint16_t read_10_baht();
    void begin();
    void reset();
    bool commit();
    bool get_auto_lcd_off();
    void set_auto_lcd_off(bool);
};

#endif /* __EEPROM_HPP__ */