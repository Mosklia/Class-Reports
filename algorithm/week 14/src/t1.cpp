#include <iostream>
#include <algorithm>
#include <queue>

struct segment
{
    size_t s, t;

    segment(int __s = 0, int __t = 0)
        : s(__s), t(__t)
    {
    }

    constexpr bool operator<(const segment &other) const
    {
        if (this->t != other.t)
        {
            return this->t < other.t; 
        }
        else
        {
            return this->s < other.s;
        }
    }
};

segment segs[15][1005];
size_t cnt[15];

size_t solve(segment segs[], size_t n, size_t k)
{
    size_t res = 0;

    std::queue<segment> que;
    for (int i = 0; i < n; ++i)
    {
        while (!que.empty() && que.front().t <= segs[i].s)
        {
            que.pop();
        }

        if (que.size() < k)
        {
            que.push(segs[i]);
            ++res;
        }
    }

    return res;
}

int main()
{
    size_t n, k, res = 0;
    std::cin >> n >> k;

    for (size_t i = 0; i < n; ++i)
    {
        size_t s, t, tape;
        std::cin >> s >> t >> tape;

        segs[tape][cnt[tape]++] = segment(s, t);
    }

    for (size_t i = 0; i <= 14; ++i)
    {
        std::sort(segs[i], segs[i] + cnt[i]);
        res += solve(segs[i], cnt[i], k);
    }

    std::cout << res << std::endl;
}
