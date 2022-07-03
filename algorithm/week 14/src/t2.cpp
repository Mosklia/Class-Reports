#include <string>
#include <iostream>
#include <algorithm>

#include <cstring>

constexpr size_t MAXN = 10000, CHARSET_SZ = 26;

size_t arr[MAXN + 5];
bool vis[128], has_next[MAXN + 5][128];

std::string dfs(char level, const std::string &s)
{
    if (level < 'a')
    {
        return s;
    }

    size_t pos = s.rfind(level);
    if (pos == std::string::npos)
    {
        return dfs(level - 1, s);
    }

    std::string s1 = dfs(level - 1, s.substr(0, pos));
    std::string s2 = dfs(level - 1, s.substr(pos + 1));
    std::string res = "";

    std::memset(vis, 0, sizeof(vis));
    for (auto x : s1)
    {
        if (x < level && !vis[x])
        {
            res += x;
            vis[x] = true;
        }
    }
    res += level;
    for (auto x : s2)
    {
        if (x < level && !vis[x])
        {
            res += x;
            vis[x] = true;
        }
    }
    std::cerr << "--- " << level << ' ' << res << std::endl;
    return res;
}

int main()
{
    size_t n;
    std::string s, ans;
    std::cin >> n >> s;
    n = s.length();

    std::cout << dfs('z', s) << std::endl;
}