#include <fstream>
#include <algorithm>
#include <iostream>

int main()
{
    
    std::ifstream file("input");
    if(!file.is_open())
        throw std::runtime_error("OMG WTF ICQ");

    char inp;
    long long int cnt = 0, max = -1;
    file.get(inp);
    std::string ans, buffer;
    while(!file.eof())
    {
        if (inp != '\0'){
            ++cnt;
            buffer.append(&inp);
        }
        else{
            if (max < cnt){
                max = cnt;
                ans = buffer;
            }
            cnt = 0;
            buffer = std::string();
        }
        std::cout << buffer << std::endl;
        file.get(inp);
    }
    std::cout << ans;

}
