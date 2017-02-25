#include "roboclaw/roboclaw.h"
#include <iostream>
#include <string>

int main()
{
    Roboclaw claw("/dev/serial0",115200);
    char ver[256];
    claw.ReadVersion(0x80,ver);
    std::cout << "Roboclaw version : " << std::string(ver) << std::endl;
    
    int m1 = claw.ReadEncM1(0x80);
    std::cout << "Roboclaw encoder : " << m1 << std::endl;
    return 0;
}
