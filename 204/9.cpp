#include <iostream>
#include <vector>
#include <sstream>
#include <string>


int main()
{
    std::vector<double> First;
    std::string str;
    std::getline(std::cin, str);
    std::stringstream inp;
    inp << str;
    double a = -1; 
    size_t cnt = 0;
    for(float tmp = 0; inp >> tmp;){
        if (cnt == 1)
            a = tmp;
        else
            First.push_back(tmp);
        ++cnt;
    }
    std::vector<double> Ans(First.size() + 1, 0);
    
    for (long long int i = 0; i < First.size(); ++i){
        Ans[i + 1] += First[i];
        Ans[i] -= a * First[i];
    }
        
    for(auto elem : Ans)
        std::cout << elem << ' ';
    
    return 0;
}
