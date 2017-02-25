#include "roboclaw/roboclaw.h"
#include <iostream>
#include <string>
#include <bitset>

int main()
{
    Roboclaw claw("/dev/serial0",115200);
    char ver[256];
    claw.ReadVersion(0x80,ver);
    std::cout << "Roboclaw version : " << std::string(ver) << std::endl;

    uint8_t status = 0;
    bool valid = false;
    for(;;)
    {
        int m1 = claw.ReadEncM1(0x80,&status,&valid);
        std::cout << "Roboclaw encoder : " << m1 << " status : " << std::bitset<8>(status) << " valid : "<< valid<< std::endl;
    }
    
    return 0;
}
