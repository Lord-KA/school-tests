#include <iostream>

void func5()
{
    char elem;
    std::cin.get(elem);
    long long int cnt = -2, i = 0;
    while (elem != '\n'){
        if (elem == 'f' && cnt < 0)
            ++cnt;
        if (cnt == 0)
            cnt = i;
        ++i;
        std::cin.get(elem);
    }
    std::cout << cnt;
}
