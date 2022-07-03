#include <iostream>
#include <algorithm> // std::swap
#include <cstdlib>

constexpr int MAXN = 100;
int arr[MAXN + 3];

void quick_sort(int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int len = right - left + 1;
    int pivot = arr[rand() % len + left];
    // int pivot = arr[left];
    // std::cout << left << ' ' << right << ' ' << pivot << ' ';

    int fast = left, slow = left, inv = right;

    while (fast <= inv)
    {
        if (arr[fast] < pivot)
        {
            std::swap(arr[fast++], arr[slow++]);
        }
        else if (arr[fast] == pivot)
        {
            ++fast;
        }
        else
        {
            std::swap(arr[fast], arr[inv--]);
        }
    }

    // for (int i = left; i <= right; ++i)
    // {
    //     std::cout << arr[i] << ' ';
    // }
    // std::cout << std::endl;

    quick_sort(left, slow - 1);
    quick_sort(fast, right);
}

int main()
{
    srand(19260817U);

    int n = 0;
    while (std::cin >> arr[++n]) continue;

    quick_sort(1, n - 1);

    for (int i = 1; i <= n - 1; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}