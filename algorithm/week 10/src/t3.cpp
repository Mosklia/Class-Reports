#include <iostream>
#include <algorithm>
#include <cstdlib>

const size_t MAXN = 100u;
size_t n;
int arr[MAXN];
int ans;
bool flag = false;

void partly_sort(size_t l, size_t r)
{
    if (l >= r || flag)
    {
        ans = arr[l];
        return;
    }

    int pivot = arr[l];
    for (int i = l; i <= r; ++i)
    {
        if (arr[i] < pivot)
        {
            pivot = arr[i];
        }
    }
    size_t fast = l, slow = l, inv = r;

    while (fast <= inv)
    {
        if (arr[fast] < pivot)
        {
            std::swap(arr[fast++], arr[slow++]);
        }
        else if (pivot < arr[fast])
        {
            std::swap(arr[inv--], arr[fast]);
        }
        else
        {
            ++fast;
        }
    }

    // std::cout << "---" << slow << ' ' << fast << std::endl;
    if (slow - l >= (n + 1) / 2)
    {
        partly_sort(l, slow - 1);
    }
    else if (fast - slow >= (n + 1) / 2)
    {
        ans = pivot;
        flag = true;
    }
    else
    {
        partly_sort(fast, r);
    }
}

int main()
{
    std::cin >> n;
    for (size_t i = 1u; i <= n; ++i)
    {
        std::cin >> arr[i];
    }
    partly_sort(1u, n);
    std::cout << ans << std::endl;

    // for (size_t i = 1u; i <= n; ++i)
    // {
    //     std::cout << arr[i] << ' ';
    // }
    // std::cout << std::endl;
}