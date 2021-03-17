#include <fstream>
#include <iostream>

int main()
{
    double inp;
    std::cin >> inp;
    long long int allsec = inp * 120;
    //std::cout << allsec << std::endl;
    long long int min, sec, hour;
    hour = allsec / 3600;
    min = (allsec - hour * 3600) / 60;
    sec = allsec - hour * 3600 - min * 60;
    std::cout << hour << ' ' << min << ' ' << sec;
}
