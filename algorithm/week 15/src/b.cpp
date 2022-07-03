#include <iostream>
#include <algorithm> // std::max

using stat_t = unsigned long long;

constexpr size_t MAXN = 50;

stat_t graph_bin[MAXN]; // 位模式表示某个点能够直接访问哪些点（包括自身）
int graph[MAXN][MAXN];  // 题目输入的图

/**
 * @brief 递归搜索包含某个结点的最大团的大小
 * 
 * @param n 见题目
 * @param source 当前搜索的结点
 * @param visited 当前访问过的所有结点的二进制表示，应传入未访问过 source 时的值
 * @param accessible 允许继续搜索的全部结点，应传入未访问过 source 时的值
 * @return size_t 当前状态下从 source 结点可扩展出的团的最大大小
 */
size_t dfs(size_t n, size_t source, stat_t visited, stat_t accessible)
{
    const stat_t source_bin = 1U << source;
    // source 已访问过，无需再次访问
    if (source_bin & visited)
    {
        return 0;
    }
    // std::cerr << "-- " << source << ' ' << visited << std::endl;

    visited |= source_bin;
    accessible &= graph_bin[source];

    size_t res = 1; // 从 source 最大可以扩展出团的大小，即答案
    for (size_t i = 0; i < n; ++i)
    {
        const stat_t next_bin = 1U << i;    // 尝试访问的下一个结点的二进制表示
        if (
            (visited & next_bin)                    // 尝试访问的结点已经访问过
            || !(accessible & next_bin)             // 尝试访问的结点不可达
            || ((graph_bin[i] & visited) != visited)  // 从尝试访问的结点不可达全部已访问的结点
        )
        {
            continue;
        }

        // std::cerr << "--- " << source << ' ' << i << ' ' << visited << std::endl;
        res = std::max(res, dfs(n, i, visited, accessible) + 1);
    }

    return res;
}

int main()
{
    size_t n;
    std::cin >> n;

    // 输入给定的图，并标记每个点自己可以到达自己
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            std::cin >> graph[i][j];
            if (i == j)
            {
                graph[i][j] = 1;
            }
        }
    }

    // 筛除掉无用的单向边，并计算 graph_bin
    for (size_t i = 0; i < n; ++i)
    {
        // std::cerr << "--- ";
        for (size_t j = 0; j < n; ++j)
        {
            graph[i][j] &= graph[j][i];
            graph_bin[i] |= graph[i][j] << j;
            // std::cerr << graph[i][j] << ' ';
        }
        // std::cerr << std::endl;
    }

    size_t res = 0;
    for (size_t i = 0; i < n; ++i)
    {
        res = std::max(res, dfs(n, i, 0ULL, ~0ULL));
    }

    std::cout << res << std::endl;
}