#include <iostream>
#include <fstream>


void func6()
{
    std::fstream file("input");
    if(!file.is_open())
        throw std::runtime_error("OMG WTF ICQ");
    
    long long int k = file.tellg() / sizeof(int32_t), q = 4, max = -1, min = -1;
    int32_t maxV, minV;
 
    //std::cout << file.tellg();
    for (int32_t i = 0, tmp; i < k; ++i){
        file.read(reinterpret_cast<char*>(&tmp), q);

        if (!i){
            maxV = tmp;
            minV = tmp;
            max = i;
            min = i;
        }
        //std::cout << tmp << '\n'; //DEBUG
        if (maxV < tmp){
            maxV = tmp;
            max = i;
        }
            
        if (minV > tmp){
            minV = tmp;
            min = i;
        }
            
    }
    //std::cout << std::endl;
    //std::cout << minV << ' ' << min << ' ' << maxV << ' ' << max << std::endl;
    
    file.close();

    file.open("input");
    
    file.seekg(q * min, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&maxV), sizeof(maxV));
    file.seekg(q * max, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&minV), sizeof(minV));   

    file.close();
}
