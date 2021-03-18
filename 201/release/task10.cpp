#include <fstream>
#include <iostream>
#include <cmath>

void func10()
{
    double inp;
    std::cin >> inp;
    
    while (inp >= 720) inp -= 720;
    // std::cout << inp * 120 << std::endl;
    long long int allsec = std::round(inp * 100) / 100 * 120;
    // std::cout << allsec << std::endl;
    long long int min, sec, hour;
    hour = allsec / 3600;
    min = (allsec - hour * 3600) / 60;
    sec = allsec - hour * 3600 - min * 60;
    std::cout << hour << ' ' << min << ' ' << sec;
}
