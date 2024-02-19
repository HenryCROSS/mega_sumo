#include <common.hpp>
#include <debug.hpp>
#include <hardware_interface.hpp>

void debug::motor_test(){
    HW_API::forward();
    delay(1000);
    HW_API::emerg_stop();
    delay(1000);
    HW_API::turn_left();
    delay(1000);
    HW_API::emerg_stop();
    delay(1000);
    HW_API::turn_right();
    delay(1000);
    HW_API::emerg_stop();
    delay(999999);
}

void debug::sensor_test(){
    // G::left_on_line = digitalRead(G::SENSOR_L);
    // G::right_on_line = digitalRead(G::SENSOR_R);
    HW_API::read_data();
    Serial.print("left_on_line: ");
    Serial.print(G::left_on_line);
    Serial.print("------");
    Serial.print("right_on_line: ");
    Serial.print(G::right_on_line);
    delay(500);
}

void debug::correct_direction_test(){
    delay(1000);
    HW_API::forward();
    delay(2000);
    HW_API::emerg_stop();
    delay(9999999);
}