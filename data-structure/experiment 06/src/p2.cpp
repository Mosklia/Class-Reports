#include <iostream>
#include <algorithm>

const int maxn = 100'000;
const int maxm = 200'000;

struct edge
{
    int from, to;
    int weight;

    edge(int f = 0, int t = 0, int w = 0)
    : from(f), to(t), weight(w)
    {
    }

    bool operator< (const edge &other) const
    {
        return weight < other.weight;
    }
};

edge e[maxm];
int v[maxn + 1]; // 并查集中各个结点的代表元

/**
 * @brief 并查集的 find 操作，仅使用路径压缩
 * 
 * @param p 需要查找代表元的点
 * @return p 所在集合的代表元
 */
int find(int p)
{
    return v[p] == p ? p : (v[p] = find(v[p]));
}

int main()
{
    int n, m;

    while (std::cin >> n >> m)
    {
        int ans = 0; // 最小生成树代价
        int tot = 0; // 已连接的树边条数
        // 如果整幅图连通，tot 最终应为 n - 1

        // 初始化并查集
        for (int i = 1; i <= n; ++i)
        {
            v[i] = i;
        }

        for (int i = 0; i < m; ++i)
        {
            std::cin >> e[i].from >> e[i].to >> e[i].weight;
        }

        std::sort(e, e + m); // Kruskal 第一步：排序

        // Kruskal 第二步：选边
        for (int i = 0; i < m; ++i)
        {
            int s = e[i].from, t = e[i].to, w = e[i].weight;

            // 代表元不同，说明不在一个集合
            if (find(s) != find(t))
            {
                // 选择这条边
                ans += w;
                ++tot;

                // 将它们的代表元置为相同
                v[find(s)] = find(t);
            }
        }

        if (tot == n - 1)
        {
            std::cout << ans << std::endl;
        }
        else // 图不连通
        {
            std::cout << "impossible" << std::endl;
        }
    }
}