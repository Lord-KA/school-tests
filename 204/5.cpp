#include <iostream>

int main()
{
    char elem;
    std::cin.get(elem);
    long long int cnt = -2, i = 0;
    while (elem != '\n'){
        if (elem == 'j' && cnt < 0)
            ++cnt;
        if (cnt == 0)
            cnt = i;
        ++i;
        std::cin.get(elem);
    }
    std::cout << cnt;

    return 0;
}
