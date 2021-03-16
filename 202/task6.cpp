#include <iostream>
#include <fstream>
#include <cstdint>

void func6()
{
    std::fstream f("input");
    if (!f.is_open()) exit(1);
    int32_t nump,numn, num;
    std::size_t index = 0, index1 = 0, index2 = 0;
    bool flag1 = false, flag2=false;
    while (!f.eof())
    {
        f.read(reinterpret_cast<char*>(&num), 4);
        if (num > 0 && flag1 == false) {
            nump = num;
            index1 = index;
            flag1 = true;
        }
        if (num < 0 && flag2 == false)
        {
            numn = num;
            index2 = index;
            flag2 = true;
        }

        ++index;

    } 
    f.clear();
    f.sync();
    f.seekp(4 * index1, std::fstream::beg);
    f.write(reinterpret_cast<char*>(&numn),4);

    f.close();

    f.open("input", std::fstream::binary | std::fstream::in | std::fstream::out);

    f.seekp(4 * index2, std::fstream::beg);
    f.write(reinterpret_cast<char*>(&nump), 4);
    f.close();

}

/*int main()
{
    func6();
    return 0;
}*/
