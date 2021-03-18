#include <fstream>
#include <iostream>

void func1()
{
    std::ifstream file("input");
    if(!file.is_open())
        throw std::runtime_error("OMG WTF ICQ");

    double inp,
          delta = 0.00000001;
    size_t cnt = 0;
    while(file >> inp)
    {
        if (inp >= delta)
            ++cnt;
    }
    std::cout << cnt;
}
