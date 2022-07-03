#include <iostream>
#include <algorithm>

constexpr int MAXN = 100;

int arr[MAXN + 3];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> arr[i];
    }
    for (int i = n; i >= 2; --i)
    {
        arr[i] -= arr[i - 1];
    }
    arr[1] = 0;
    arr[n + 1] = -1;
    arr[n + 2] = 1;

    int len = 0;
    for (int i = 1; i <= n + 2; ++i)
    {
        if (arr[i] <= 0)
        {
            ++len;
        }
        else
        {
            if (len >= 2)
            {
                for (int j = i - len; j < i; ++j)
                {
                    arr[i] = 0;
                }
            }
            len = 0;
        }
    }
    for (int i = 2; i < n; ++i)
    {
        if (arr[i] >= 0)
        {
            continue;
        }

        if (arr[i - 1] > arr[i + 1] && arr[i + 1] + arr[i] <= 0)
        {
            arr[i + 1] = arr[i] = 0;
        }
        else if (arr[i - 1] < arr[i + 1] && arr[i - 1] + arr[i] <= 0)
        {
            arr[i - 1] = arr[i] = 0;
        }
    }

    int sum = 0;
    for (int i = 2; i <= n; ++i)
    {
        sum += arr[i];
    }
    std::cout << sum << std::endl;
}