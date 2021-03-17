#include <iostream>
#include <vector> 

int main()
{
    size_t m, n;
    std::cin >> m >> n;
    std::vector<std::vector<size_t>> Map(m, std::vector<size_t>(n, 0));
    std::cout << Map.size() << ' ' << Map[0].size(); //DEBUG
    Map[0][n - 1] = 2;
    

    for (size_t i=0; i < m; ++i){
        for(size_t j=0; j < n; ++j)
            std::cout << Map[i][j] << ' ';
        std::cout << std::endl;
    }
    return 0;
    for (size_t i=n-2; i >= 0; i--)
        Map[0][i] = 2 * Map[0][i + 1];

    for (size_t i=1; i < m; i++)
    {
        for (size_t j=0; j < n - 1; j++)
        {
            Map[i][j] = Map[i - 1][j + 1];
        }
        Map[i][n - 1] = 2 * Map[i - 1][n - 1];
    }


    for (size_t i=0; i < m; ++i){
        for(size_t j=0; j < n; ++j)
            std::cout << Map[i][j] << ' ';
        std::cout << std::endl;
    }
}
