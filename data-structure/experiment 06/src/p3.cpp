#include <iostream>
#include <algorithm>
#include <queue> // For std::priority_queue

const int maxm = 150'000;
const int maxn = 150'000;
const int inf = 0X3F3F3F3F;

// Vertex
struct vertex
{
    int head, dist;

    vertex(int h = 0, int d = inf)
    : head(h), dist(d)
    {
    }
};

// Edge
struct edge
{
    int to, weight, next;

    edge(int t = 0, int w = 0, int n = 0)
    : to(t), weight(w), next(n)
    {
    }
};

vertex v[maxn + 3];
edge e[maxm + 3];
int edges;

void dijkstra(int s)
{
    // 比较器
    auto comp = [](const std::pair<int,int> &elem1, const std::pair<int,int> &elem2)
    {
        return elem1.second > elem2.second;
    };

    // Heap used in heap-optimized Dijkstra's algorithm.
    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        decltype(comp)
    > q(comp);

    q.push(std::make_pair(s, 0));

    while (!q.empty())
    {
        // 堆顶的点
        int p = q.top().first;
        int d = q.top().second;

        q.pop();

        if (v[p].dist != inf)
        {
            continue;
        }

        v[p].dist = d;

        for (int i = v[p].head; i; i = e[i].next)
        {
            int cur = e[i].to;

            if (v[cur].dist == inf)
            {
                q.push(std::make_pair(cur, v[p].dist + e[i].weight));
            }
        }
    }
}

void connect(int from, int to, int weight)
{
    e[++edges] = edge(to, weight, v[from].head);
    v[from].head = edges;
}

void clear(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        v[i] = vertex();
    }

    edges = 0;
}

int main()
{
    int n, m;
    while (std::cin >> n >> m)
    {
        for (int i = 1; i <= m; ++i)
        {
            int s, t, w;
            std::cin >> s >> t >> w;
            connect(s, t, w);
        }

        dijkstra(1);

        std::cout << (v[n].dist == inf ? -1 : v[n].dist) << std::endl;

        clear(n);
    }
}