#include <iostream>
#include <algorithm> // std::swap
#include <queue>     // std::queue

constexpr int MAXN = 10, OFFSET = 20;
constexpr long long INDEX_MASK = (1 << OFFSET) - 1;
long long arr[MAXN + 3], tot[MAXN + 3];

int res = 0;

void merge(int left, int right)
{
    const int mid = (left + right) / 2;
    std::queue<int> que_left, que_right;
    for (int i = left; i <= right; ++i)
    {
        (i <= mid ? que_left : que_right).push(arr[i]);
    }

    int cur = left;
    while (!que_left.empty() && !que_right.empty())
    {
        if (que_left.front() <= que_right.front())
        {
            // while (!que_right.empty() && que_left.front() > que_right.front())
            // {
            arr[cur++] = que_right.front();
            que_right.pop();
            // }
        }
        else
        {
            tot[que_left.front() & INDEX_MASK] += que_right.size();
            res += que_right.size();
            arr[cur++] = que_left.front();
            que_left.pop();
        }
    }

    while (!que_left.empty())
    {
        arr[cur++] = que_left.front();
        que_left.pop();
    }
    while (!que_right.empty())
    {
        arr[cur++] = que_right.front();
        que_right.pop();
    }
}

void merge_sort(int left, int right)
{
    if (left >= right)
    {
        return;
    }

    const int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);

    merge(left, right);
    // std::cout << "---" << left << ' ' << right << ' ' << res << std::endl;
}

int main()
{
    int n = 1;
    while (std::cin >> arr[n])
    {
        arr[n] = (arr[n] << OFFSET) | n;
        ++n;
    }
    merge_sort(1, n - 1);
    for (int i = 1; i < n; ++i)
    {
        std::cout << tot[i] << ' ';
    }
    std::cout << std::endl;
    // std::cout << res << std::endl;
}