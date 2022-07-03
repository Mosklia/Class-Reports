#include <algorithm>
#include <iostream>

using stat_t = unsigned short;

constexpr size_t MAXN = 16, MAXK = 16;

int nums[MAXN];

bool calc(size_t level, size_t n, int target, stat_t used, int remainder)
{
    if (level <= 0)
    {
        return true;
    }

    if (remainder == target)
    {
        for (size_t i = 0; i < n; ++i)
        {
            if (used & 1U << i)
            {
                continue;
            }
            if (nums[i] > target)
            {
                return false;
            }
            else if (nums[i] == target)
            {
                return calc(level - 1, n, target, used | 1U << i, target);
            }
            else
            {
                return calc(level, n, target, used | 1U << i, target - nums[i]);
            }
        }
        return false;
    }
    else
    {
        for (size_t i = n - 1; i != SIZE_MAX; --i)
        {
            if (used & 1U << i)
            {
                continue;
            }
            else if (nums[i] == remainder)
            {
                return calc(level - 1, n, target, used | 1U << i, target);
            }
            else if (nums[i] > remainder)
            {
                return false;
            }
            else if (calc(level, n, target, used | 1U << i, remainder - nums[i]))
            {
                return true;
            }
        }
        return false;
    }
}

int main()
{
    size_t n, k;
    int sum = 0;
    std::cin >> n >> k;

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
        sum += nums[i];
    }

    std::sort(nums, nums + n, [](int a, int b) { return a > b; });

    if (sum % k != 0)
    {
        std::cout << "False\n";
        return 0;
    }

    std::cout << (calc(k, n, sum / k, 0U, sum / k) ? "True\n" : "False\n");
}