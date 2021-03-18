#include <iostream>
#include <vector>
#include <sstream>
#include <string>


void func9()
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
    std::vector<double> Ans(2 * First.size() - 1, 0);
    
    for (long long int i = 0; i < First.size(); ++i)
        for(long long int j = 0; j < First.size(); ++j){
            if (i == 0 && j == 0)
                Ans[i + j] += First[i] * First[j] * a * a;
            else if(i == 0 || j == 0)
                Ans[i + j] += First[i] * First[j] * a;
            else
                Ans[i + j] += First[i] * First[j];
        }

        
    for(auto elem : Ans)
        std::cout << elem << ' ';
}
