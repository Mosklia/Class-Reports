#include <iostream>
#include <algorithm>

constexpr int MAXN = 100;

using val_t = long long;

val_t f[MAXN][MAXN];
int step[MAXN][MAXN];

void print_res(int lvl_x, int lvl_y)
{
    if (lvl_x == 0)
    {
        return;
    }
    std::cout << lvl_y - step[lvl_x][lvl_y] << ' ';
    print_res(lvl_x - 1, step[lvl_x][lvl_y]);
}

int main()
{
    int n, lvl_x = 0, lvl_y;
    val_t res = 0;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        f[1][i] = i;
        step[1][i] = 0;
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            for (int k = 1; k < j; ++k)
            {
                if (f[i - 1][k] * (j - k) > f[i][j])
                {
                    step[i][j] = k;
                    f[i][j] = f[i - 1][k] * (j - k);
                }
            }
            if (f[i][j] > res)
            {
                res = f[i][j];
                lvl_x = i;
                lvl_y = j;
            }
        }
    }

    std::cout << res << ' ';
    print_res(lvl_x, lvl_y);
    std::cout << std::endl;
}