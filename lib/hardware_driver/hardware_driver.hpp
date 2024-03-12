#ifndef _HW_DRIVER_HPP_

class HW_Driver
{
public:
    static void turn_left(int left_speed, int right_speed);  //
    static void turn_right(int left_speed, int right_speed); //
    static void forward(int speed);    //
    static void backward(int speed);   //
    static void emerg_stop();
};


#endif // !_HW_DRIVER_HPP_