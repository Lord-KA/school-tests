#include <iostream>
#include <fstream>


int main()
{
    std::fstream file("input");
    
    size_t k = file.tellg() / sizeof(int32_t), q = 4, pos = -1, neg = -1;
    for (int32_t i = 0, tmp; i < k; ++i){
        file.read(reinterpret_cast<char*>(&tmp), q);
        // std::cout << tmp << '\n'; //DEBUG
        if (neg == -1 && tmp < 0)
            neg = i;
        if (tmp > 0)
            pos = i;
    }
    
    file.close();
    
    
    file.open("input");
    int32_t posVal, negVal;
    
    file.seekg(q * pos, std::fstream::beg);
    file.read(reinterpret_cast<char*>(&posVal), sizeof(posVal));
    file.seekg(q * neg, std::fstream::beg);
    file.read(reinterpret_cast<char*>(&negVal), sizeof(negVal));
    
    file.seekg(q * pos, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&negVal), sizeof(negVal));
    file.seekg(q * neg, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&posVal), sizeof(posVal));   

    file.close();
}
