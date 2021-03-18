#include <iostream>
#include <fstream>

int main(){
    
    std::fstream file("output.txt", std::fstream::in | std::fstream::out | std::fstream::binary);
    int32_t s = 10, q = 4;
    file.write(reinterpret_cast<char*>(&s), q);
    ++s;
    file.write(reinterpret_cast<char*>(&s), q);
    ++s;
    file.write(reinterpret_cast<char*>(&s), q);
    ++s;
    file.write(reinterpret_cast<char*>(&s), q);
    file.close();


    file.open("output.txt", std::fstream::in | std::fstream::out | std::fstream::binary);
    int32_t one, three;
    file.read(reinterpret_cast<char*>(&one), q);
    file.seekg(4, std::fstream::cur);
    file.read(reinterpret_cast<char*>(&three), q);
    //std::cout << one << std::endl;
    //std::cout << three << std::endl;
    file.seekp(0, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&three), q);
    file.seekp(8, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&one), q);
    file.close();


    file.open("output.txt", std::fstream::in | std::fstream::out | std::fstream::binary);
    int32_t ans = 0;
    file.read(reinterpret_cast<char*>(&ans), q);
    std::cout << ans << std::endl;
    file.read(reinterpret_cast<char*>(&ans), q);
    std::cout << ans << std::endl;
    file.read(reinterpret_cast<char*>(&ans), q);
    std::cout << ans << std::endl;
    file.read(reinterpret_cast<char*>(&ans), q);
    std::cout << ans << std::endl;
    file.close();
    return 0;
}
