#include <iostream>
#include <string>

void func5()
{
    std::size_t cnt = 0, index = 0;
    std::string str;
    std::cin >> str;
    for (std::size_t i = 0; i < str.size(); ++i)
    {
        if ((str[i] == 'g') && (cnt == 1))
        {
            index = i;
            ++cnt;
            break;
        }
        if ((str[i] == 'g') && (cnt == 0)) ++cnt;    
    }

    if (cnt == 0) std::cout << -2;
    if (cnt == 1) std::cout << -1;
    if (cnt == 2) std::cout << index;

}

/*int main()
{
    func5();
    return 0;
}*/

