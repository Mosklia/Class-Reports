#include <iostream>
#include <algorithm> // std::min

constexpr size_t MAXN = 100;

int arr[MAXN + 1], vis[MAXN + 1];

int main()
{
    int n, cur = 1;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> arr[i];
        arr[i] += i;
    }

    for (int i = 1; i <= n; ++i)
    {
        while (cur <= arr[i] && cur <= n)
        {
            vis[cur++] = i;
        }
    }

    int ans = 0;
    cur = n;
    while (cur != 1)
    {
        ++ans;
        cur = vis[cur];
    }

    std::cout << ans << std::endl;
}