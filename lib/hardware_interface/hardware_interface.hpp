#ifndef _HARDWARE_INTERFACE_HPP_
#define _HARDWARE_INTERFACE_HPP_

class HW_API
{
  public:
    static void turn_left();  //
    static void turn_right(); //
    static void forward();    //
    static void backward();   //
    static void read_data();  //
    static void emerg_stop();
};

#endif // !_HARDWARE_INTERFACE_