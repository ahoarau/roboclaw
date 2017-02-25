#include "roboclaw/roboclaw.h"
#include <iostream>
#include <string>

int main()
{
    Roboclaw claw("/dev/serial0",115200);
    std::string version;
    claw.ReadVersion(0x80,version);
    std::cout << "Roboclaw version : " << version << std::endl;
    return 0;
}
