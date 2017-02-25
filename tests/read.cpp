#include "roboclaw/roboclaw.h"
#include <iostream>
#include <string>

int main()
{
    Roboclaw claw("/dev/serial0",115200);

    uint8_t status = 0;
    bool valid = false;
    for(;;)
    {
        int32_t m1 = claw.ReadEncM1(0x80,&status,&valid);
        int32_t vm1 = claw.ReadSpeedM1(0x80,&status,&valid);
        std::cout << "Roboclaw m1 encoder : " << m1 << " speed : " << vm1 << std::endl;
    }

    return 0;
}
