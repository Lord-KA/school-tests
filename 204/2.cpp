#include <fstream>
#include <iostream>
#include <cmath>

int main()
{
    std::ifstream file("input");
    double inp,
          ans;
    size_t cnt = 0;
    while(file >> inp)
    {
        if (!cnt)
            ans = inp;
        if (std::abs(inp) > std::abs(ans) || (std::abs(inp) == std::abs(ans) && inp > ans))
            ans = inp;
        ++cnt;
    }
    std::cout << ans;
}
