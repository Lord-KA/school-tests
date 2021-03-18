#include <iostream>
#include <vector> 
#include <cmath>

int main()
{
    long long int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<size_t>> Map(m);

    //std::cout << Map.size() << ' ' << Map[0].size(); //DEBUG
 
    /*//DEBUG
    for (size_t i=0; i < m; ++i){
        for(size_t j=0; j < n; ++j)
            std::cout << Map[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;
    */
    if (n == 0 || m == 0)
        return 0 ;
    for (long long int i=0; i < m; i++)
    {
        //std::cout << -i << std::endl;
        for (long long int j = -i; j < n; j++)
        {
            Map[i].push_back(std::abs(j));
            //std::cout << j;
        }
        //std::cout << '\n';
    }

    for (size_t i=0; i < m; ++i){
        for(size_t j=0; j < n; ++j)
            std::cout << Map[i][j] << ' ';
        std::cout << std::endl;
    }
}
