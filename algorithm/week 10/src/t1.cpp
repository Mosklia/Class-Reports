#include <iostream>
#include <queue>

using ans_t = unsigned long long;
const size_t MAXN = 100;

ans_t ans = 0;
size_t n;
int arr[MAXN];

void merge(size_t l, size_t r)
{
    size_t mid = (l + r) / 2;
    size_t cur = l;

    #define clear_queue(que) \
    while (!que.empty()) \
    { \
        arr[cur++] = que.front(); \
        que.pop(); \
    }

    std::queue<int> que_l, que_r;

    for (size_t i = l; i <= r; ++i)
    {
        (i <= mid ? que_l : que_r).push(arr[i]);
    }

    while (!que_l.empty() && !que_r.empty())
    {
        if (que_r.front() < que_l.front())
        {
            ans += que_l.size();
            arr[cur++] = que_r.front();
            que_r.pop();
        }
        else
        {
            arr[cur++] = que_l.front();
            que_l.pop();
        }
    }

    clear_queue(que_l);
    clear_queue(que_r);

    #undef clear_queue
}

void merge_sort(size_t l, size_t r)
{
    if (l >= r)
    {
        return;
    }

    size_t mid = (l + r) / 2;

    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, r);
}

int main()
{
    std::cin >> n;
    for (size_t i = 1; i <= n; ++i)
    {
        std::cin >> arr[i];
    }
    merge_sort(1, n);
    std::cout << ans << std::endl;
}