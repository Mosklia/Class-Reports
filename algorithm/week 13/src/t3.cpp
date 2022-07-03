#include <iostream>
#include <algorithm>

constexpr size_t MAXN = 100;
const int INF = 0X3F3F3F3F;

struct segment
{
    int s, t;

    segment(int s = 0, int t = 0) : s(s), t(t)
    {
    }

    constexpr bool operator< (const segment &seg) const
    {
        if (this->t != seg.t)
        {
            return this->t < seg.t;
        }
        else
        {
            return this->s > seg.s;
        }
    }
};

segment seg[MAXN];

std::istream& operator>>(std::istream &ist, segment &seg)
{
    return ist >> seg.s >> seg.t;
}

int main()
{
    size_t n, ans = 0;
    int min_time = INF, max_time = 0;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> seg[i];
        min_time = std::min(seg[i].s, min_time);
        max_time = std::max(seg[i].t, max_time);
    }

    std::sort(seg, seg + n);

    int cur = min_time;
    for (size_t i = 0; i < n; ++i)
    {
        if (seg[i].s < cur)
        {
            continue;
        }
        cur = seg[i].t;
        ++ans;
    }

    std::cout << ans << std::endl;
}