#include <iostream>
#include <algorithm>

constexpr int MAXN = 100;

int a[MAXN], f[2][MAXN], g[2][MAXN];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    f[0][0] = -2147483647;
    f[1][0] = a[0];
    g[0][0] = 0;
    g[1][0] = -2147483647;

    for (int i = 1; i < n; ++i)
    {
        f[0][i] = std::max(f[0][i - 1], f[1][i - 1]);
        f[1][i] = f[0][i - 1] + a[i];
        g[0][i] = std::max(g[0][i - 1], g[1][i - 1]);
        g[1][i] = g[0][i - 1] + a[i];
    }

    if (n == 1)
    {
        std::cout << a[0] << std::endl;
    }
    else
    {
        std::cout << std::max(f[0][n - 1], std::max(g[0][n - 1], g[1][n - 1])) << std::endl;
    }
}