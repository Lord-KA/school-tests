#include <fstream>
#include <algorithm>
#include <iostream>

int main()
{
    
    std::ifstream file("input");
    char inp;
    long long int cnt = 0, ans;
    file.get(inp);
    while(!file.eof())
    {
        if (inp != '\0')
            ++cnt;
        else{
            ans = std::min(ans, cnt);
            cnt = 0;
        }
        file.get(inp);
    }
    std::cout << ans;

}
