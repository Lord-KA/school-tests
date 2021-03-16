#include <fstream>
#include <iostream>

const int32_t INF = 1215752192;

int main() //TODO test this shit
{
    /*
    std::fstream w("input");
    for(int32_t i = -5; i < 5; ++i)
        w.write(reinterpret_cast<char*>(&i), 4);
    w.close();
    */

    std::fstream file("input");
    int32_t temp, q=4, cnt = 0, k = 0, m = INF; // k - the number of numbers; m - position to place the sum (after m-th number)
    for (int32_t i = 0, tmp; !file.eof(); ++i){
        ++k;
        file.read(reinterpret_cast<char*>(&tmp), q);
        std::cout << tmp << '\n';
        if (tmp >= 0)
            ++cnt;
        if (m == INF && tmp > 0)
            m = i;
    }
    file.seekp(q * m, std::fstream::beg);
    file.read(reinterpret_cast<char*>(&temp), q);
    std::cout << cnt << ' ' << m << ' ' << k << std::endl; //DEBUG
    file.close();
        
    file.open("input");
    file.seekp(q * m, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&cnt), q);
    file.seekp(q * (m + 1), std::fstream::beg);
    for(int32_t i = m + 1, anotherTemp; i < k; ++i){
        file.read(reinterpret_cast<char*>(&anotherTemp), q);
        file.seekp(q * i, std::fstream::beg);
        file.write(reinterpret_cast<char*>(&temp), q);
        file.seekp(q * (i + 1), std::fstream::beg);
        temp = anotherTemp;
        std::cout << temp << std::endl;
    }

    file.seekp(0, std::fstream::end);
    file.write(reinterpret_cast<char*>(&temp), q);
    file.close();
}

