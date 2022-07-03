#include <iostream>
#include <algorithm> // std::sort

constexpr int MAXT = 100, MAXN = 100;

struct segment
{
    int begin, end;

    segment(int begin = 0, int end = 0) : begin(begin), end(end)
    {
    }

    int length() const
    {
        return end - begin + 1;
    }

    bool operator< (const segment &other) const
    {
        if (this->begin != other.begin)
        {
            return this->begin < other.begin;
        }
        else
        {
            return this->end < other.end;
        }
    }

};

segment segs[MAXN + 1];

std::istream &operator>> (std::istream &ist, segment &seg)
{
    return ist >> seg.begin >> seg.end;
}

int main()
{
    int t, n, cur = -1, tot = 0;
    std::cin >> t >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> segs[i];
    }

    std::sort(segs, segs + n);
    segs[n] = segment(MAXT + 100, MAXT + 101);

    for (int i = 0; i < n && cur < t;)
    {
        int temp = cur;
        bool flag = false;
        while (segs[i].begin <= cur + 1)
        {
            temp = std::max(temp, segs[i].end);
            ++i;
            flag = true;
        }
        if (!flag)
        {
            std::cout << "-1\n";
            return 0;
        }
        cur = temp;
        ++tot;
    }

    if (cur < t)
    {
        std::cout << "-1\n";
    }
    else
    {
        std::cout << tot << std::endl;
    }
}