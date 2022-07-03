#include <iostream>
#include <algorithm>

int main()
{
    size_t n, tot = 0;
    unsigned int cur;
    
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> cur;
        if (cur & 1)
        {
            ++tot;
        }
    }
    std::cout << std::min(tot, n - tot) << std::endl;
}