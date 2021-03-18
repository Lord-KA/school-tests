#include <fstream>
#include <iostream>

int main()
{
    std::ifstream file("input");
    double inp,
          delta = 0.00000001,
          k = 100;
    size_t cnt = 0;
    while(file >> inp)
    {
        if (inp >= delta)
            ++cnt;
    }
    std::cout << cnt;
}
