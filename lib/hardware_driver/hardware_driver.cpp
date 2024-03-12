#include <hardware_driver.hpp>
#include <configs.hpp>
#include <hardware_interface.hpp>


void car_go_forward(int speed)
{
    HW_API::wheel_move_speed(G::LEFT_MOTOR_PIN, speed - G::DELTA);
    HW_API::wheel_move_speed(G::RIGHT_MOTOR_PIN, speed + G::DELTA);
    HW_API::wheel_forward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
    HW_API::wheel_forward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
}

void car_go_forward_by_speed(int left_wheel_speed, int right_wheel_speed)
{
    HW_API::wheel_move_speed(G::LEFT_MOTOR_PIN, left_wheel_speed - G::DELTA);
    HW_API::wheel_move_speed(G::RIGHT_MOTOR_PIN, right_wheel_speed);
    HW_API::wheel_forward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
    HW_API::wheel_forward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
}

void car_go_backward(int speed)
{
    HW_API::wheel_move_speed(G::LEFT_MOTOR_PIN, speed - G::DELTA);
    HW_API::wheel_move_speed(G::RIGHT_MOTOR_PIN, speed + G::DELTA);
    HW_API::wheel_backward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
    HW_API::wheel_backward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
}

void car_go_backward_by_speed(int left_wheel_speed, int right_wheel_speed)
{
    HW_API::wheel_move_speed(G::LEFT_MOTOR_PIN, left_wheel_speed);
    HW_API::wheel_move_speed(G::RIGHT_MOTOR_PIN, right_wheel_speed);
    HW_API::wheel_backward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
    HW_API::wheel_backward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
}

void car_turn_right_by_speed(int left_wheel_forward_speed, int right_wheel_backward_speed)
{
    HW_API::wheel_move_speed(G::LEFT_MOTOR_PIN, left_wheel_forward_speed);
    HW_API::wheel_move_speed(G::RIGHT_MOTOR_PIN, right_wheel_backward_speed);
    HW_API::wheel_forward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
    HW_API::wheel_backward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
}

void car_turn_left_by_speed(int left_wheel_backward_speed, int right_wheel_forward_speed)
{
    HW_API::wheel_move_speed(G::LEFT_MOTOR_PIN, left_wheel_backward_speed);
    HW_API::wheel_move_speed(G::RIGHT_MOTOR_PIN, right_wheel_forward_speed);
    HW_API::wheel_forward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
    HW_API::wheel_backward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
}

void HW_Driver::turn_left(int left_speed, int right_speed)
{
    car_turn_left_by_speed(left_speed, right_speed);
}

void HW_Driver::turn_right(int left_speed, int right_speed)
{
    car_turn_right_by_speed(left_speed, right_speed);
}

void HW_Driver::forward(int speed)
{
    car_go_forward(speed);
}

void HW_Driver::backward(int speed)
{
    car_go_backward(speed);
}

void HW_Driver::emerg_stop()
{
    car_go_backward(0);
}
