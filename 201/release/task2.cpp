#include <fstream>
#include <iostream>

void task2() 
{
    std::ifstream file("input");
    if (!file.is_open())
        throw std::runtime_error("OMG WTF ICQ");

    double inp,
          ans;
    size_t cnt = 0;
    while(file >> inp)
    {
        if (!cnt)
            ans = inp;
        if (inp > ans)
            ans = inp;
        ++cnt;
    }
    std::cout << ans;
}
