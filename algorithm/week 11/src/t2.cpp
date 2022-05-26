#include <iostream>
#include <algorithm>

const int MAXN = 1000, MAXV = 1000;

int w[MAXN], f[MAXV + 1];

int main()
{
    int n, v;
    std::cin >> n >> v;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> w[i];
    }
    for (int i = 0; i < n; ++i)
    {
        int sz;
        std::cin >> sz;
        for (int j = v; j >= sz; --j)
        {
            f[j] = std::max(f[j], f[j - sz] + w[i]);
        }

    // for (int i = 0; i <= v; ++i)
    //     std::cout << f[i] << ' ';
    // std::cout << std::endl;
    }

    std::cout << f[v] << std::endl;
    return 0;
}
