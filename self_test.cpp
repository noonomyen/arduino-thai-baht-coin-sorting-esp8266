#include "self_test.hpp"

void self_test::counting() {
    LCD::clear();
    LCD::print("Counting test...", " [x25]  random ");
    delay(3000);
    for (uint16_t i = 0; i < 30; i++) {
        LCD::set_1_baht(25 * i);
        LCD::set_5_baht(25 * i);
        LCD::set_10_baht(25 * i);
        LCD::refresh();
        delay(500);
    };
    delay(1000);
    LCD::clear();
    LCD::print("Counting test...", " x25  [random] ");
    randomSeed(millis());
    delay(3000);
    for (uint16_t i = 0; i < 5; i++) {
        LCD::set_1_baht(random(0, 999));
        LCD::set_5_baht(0);
        LCD::set_10_baht(0);
        LCD::refresh();
        delay(500);
    };
    for (uint16_t i = 0; i < 5; i++) {
        LCD::set_1_baht(0);
        LCD::set_5_baht(random(0, 999));
        LCD::set_10_baht(0);
        LCD::refresh();
        delay(500);
    };
    for (uint16_t i = 0; i < 5; i++) {
        LCD::set_1_baht(0);
        LCD::set_5_baht(0);
        LCD::set_10_baht(random(0, 999));
        LCD::refresh();
        delay(500);
    };
    for (uint16_t i = 0; i < 5; i++) {
        LCD::set_1_baht(random(0, 500));
        LCD::set_5_baht(random(0, 500));
        LCD::set_10_baht(random(0, 500));
        LCD::refresh();
        delay(500);
    };
    for (uint16_t i = 0; i < 5; i++) {
        LCD::set_1_baht(random(0, 999));
        LCD::set_5_baht(random(0, 999));
        LCD::set_10_baht(random(0, 999));
        LCD::refresh();
        delay(500);
    };
    delay(1000);
    LCD::clear();
    LCD::print("Exit...");
    delay(1000);
};
