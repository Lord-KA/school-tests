#include <iostream>
#include <cmath>

int main()
{
    size_t m, n;
    double tmp, ans;
    std::cin >> m >> n;
    for (size_t i=0; i < m; ++i){
        std::cin >> ans;
        for (size_t j=1; j < n; ++j){
            std::cin >> tmp;    
            if (std::abs(tmp) > std::abs(ans))
                ans = tmp;
        }
        std::cout << ans;
    }

}
