#include <iostream>
#include <vector>
#include <sstream>
#include <string>


int main()
{
    std::vector<float> First;
    std::string str;
    std::getline(std::cin, str);
    std::stringstream inp;
    inp << str;
    
    for(float tmp = 0; inp >> tmp;)
        First.push_back(tmp);
    
    std::vector<float> Ans(First.size() + 1, 0);
    float a = 1; //TODO find out what the fuck is a;
    
    for (long long int i = 0; i < First.size(); ++i){
        Ans[i + 1] += First[i];
        Ans[i] -= a * First[i];
    }
        
    Ans.pop_back();
    for(auto elem : Ans)
        std::cout << elem << ' ';
    
    return 0;
}
