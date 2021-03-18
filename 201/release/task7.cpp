#include <fstream>
#include <iostream>


void func7() 
{
    /*
    std::fstream w("input");
    for(int32_t i = -5; i < 5; ++i)
        w.write(reinterpret_cast<char*>(&i), 4);
    w.close();
    */

    std::fstream file("input", std::fstream::binary | std::fstream::in);
    if(!file.is_open())
        throw std::runtime_error("OMG WTF ICQ");

    file.seekg(0, std::ios::end);
    int32_t cnt = 0;   // count of negative
    long long int  m   = -1; // position of the first negative
    size_t k = file.tellg() / sizeof(int32_t); // count of numbers
    file.seekg(0, std::ios::beg);
    for (size_t i = 0; i < k; ++i) {
        int32_t tmp;
        file.read(reinterpret_cast<char*>(&tmp), sizeof(tmp));
        //std::cerr << "Read " << tmp << '\n'; //DEBUG
        if (tmp < 0)
            ++cnt;
        if (m == -1 && tmp < 0)
            m = i;
    }
    //std::cerr << "cnt = " << cnt << "\nm = " << m << '\n'; //DEBUG
    file.close();
        
    file.open("input");
    if(!file.is_open())
        throw std::runtime_error("OMG WTF ICQ");

    file.seekp(sizeof(int32_t) * m, std::fstream::beg);
    int32_t to_write = cnt;
    for (size_t i = m; i < k; ++i) {
        int32_t buffer = 0;
        if (file.eof())
            throw std::runtime_error("OMG WTF ICQ");
        file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
        file.seekp(sizeof(to_write) * i, std::fstream::beg);

        if (file.eof())
            throw std::runtime_error("OMG WTF ICQ");
        file.write(reinterpret_cast<char*>(&to_write), sizeof(to_write));
        to_write = buffer;
    }
    file.seekp(sizeof(to_write) * k, std::fstream::beg);
    if (file.eof())
        throw std::runtime_error("OMG WTF ICQ");
    file.write(reinterpret_cast<char*>(&to_write), sizeof(to_write));

    file.close();
}


