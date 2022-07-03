#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MAXV = 1000, INF = 0X3F3F3F3F;
constexpr size_t MAXN = 10;

bool is_prime[MAXV + 3], vis[MAXV + 3];
std::vector<int> primes;
std::vector<int> vars[MAXN];

void get_primes()
{
    std::fill(is_prime + 2, is_prime + MAXV + 3, true);
    for (int i = 2; i <= MAXV; ++i)
    {
        if (!is_prime[i])
        {
            continue;
        }
        // std::cerr << i << ' ';

        primes.push_back(i);
        for (int j = 2; j * i <= MAXV; ++j)
        {
            is_prime[j * i] = false;
        }
    }
}

int calc(int level, int sum)
{
    static int res = INT32_MAX;

    if (level < 0)
    {
        res = std::min(res, sum);
        return res == INT32_MAX ? -1 : res;
    }

    for (const auto &x : vars[level])
    {
        if (vis[x])
        {
            continue;
        }

        vis[x] = true;
        calc(level - 1, sum + x);
        vis[x] = false;
    }

    return res == INT32_MAX ? -1 : res;
}

int main()
{
    get_primes();

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        std::cin >> temp;

        for (auto &x : primes)
        {
            if (temp % x == 0)
            {
                vars[i].push_back(x);
                while (temp % x == 0)
                {
                    temp /= x;
                }
            }
        }
    }

    std::cout << calc(n - 1, 0) << std::endl;
}