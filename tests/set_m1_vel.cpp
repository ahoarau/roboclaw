#include "roboclaw/roboclaw.h"
#include <iostream>
#include <string>
#include <unistd.h>

int main()
{
    Roboclaw claw("/dev/serial0",115200);
    std::cout << "Setting velocity to 15000" << '\n';
    claw.SpeedM1(0x80,15000);
    usleep(1E6);
    std::cout << "Setting velocity to -15000" << '\n';

    claw.SpeedM1(0x80,-15000);
    usleep(1E6);
    std::cout << "Setting velocity to 0" << '\n';

    claw.SpeedM1(0x80,0);
    return 0;
}
