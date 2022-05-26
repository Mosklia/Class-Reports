#include <iostream>
#include <algorithm>
#include <functional>

const int modifier[] = {-1, 1};
const std::function<int(int, int)> fun[] =
{
    [](int a, int b) { return std::min(a, b); },
    [](int a, int b) { return std::max(a, b); }
};

const int MAXN = 20;

int a[MAXN], f[MAXN][MAXN];

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        f[i][i] = a[i] * modifier[n & 1];
    }

    for (int i = 2; i <= n; ++i)
    {
        auto opt = fun[(i ^ n ^ 1) & 1];
        auto mod = modifier[(i ^ n ^ 1) & 1];
        for (int j = 0; j < n - i + 1; ++j)
        {
            int k = j + i - 1;
            f[j][k] = opt(f[j + 1][k] + a[j] * mod, f[j][k - 1] + a[k] * mod);
        }
    }

    std::cout << (f[0][n - 1] >= 0 ? "True" : "False") << std::endl;
    // std::cout << f[0][n - 1] << std::endl;  
}