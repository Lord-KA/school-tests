#include <fstream>
#include <iostream>


int main() 
{
    /*
    std::fstream w("input");
    for(int32_t i = -5; i < 5; ++i)
        w.write(reinterpret_cast<char*>(&i), 4);
    w.close();
    */

    std::fstream file("input");
    file.seekg(0, std::ios::end);
    int32_t cnt = 0;   // count of positives
    size_t  m   = -1, // position of the last positive
            k   = file.tellg() / sizeof(int32_t); // count of numbers
    file.seekg(0, std::ios::beg);
    for (size_t i = 0; i < k; ++i) {
        int32_t tmp;
        file.read(reinterpret_cast<char*>(&tmp), sizeof(tmp));
        //std::cerr << "Read " << tmp << '\n'; /DEBUG
        if (tmp >= 0)
            ++cnt;
        if (tmp > 0)
            m = i;
    }
    //std::cerr << "cnt = " << cnt << "\nm = " << m << '\n'; //DEBUG
    m += 1; // after the last positive
    file.close();
        
    file.open("input");
    file.seekp(sizeof(int32_t) * m, std::fstream::beg);
    int32_t to_write = cnt;
    for (size_t i = m; i < k; ++i) {
        int32_t buffer = 0;
        file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
        file.seekp(sizeof(to_write) * i, std::fstream::beg);
        file.write(reinterpret_cast<char*>(&to_write), sizeof(to_write));
        to_write = buffer;
    }
    file.seekp(sizeof(to_write) * k, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&to_write), sizeof(to_write));

    file.close();
}


