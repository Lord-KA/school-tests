#include <iostream>
#include <fstream>

void func1()
{
    std::ifstream in("input");

    double temp;
    int n = 0;
    while (!in.eof())
    {
        in >> temp;
        if (temp < 1000 && temp>100)
        {
            ++n;
        }
    }
    std::cout << n;
}



/*int main()
{
    func1();
    return 0;
}*/
