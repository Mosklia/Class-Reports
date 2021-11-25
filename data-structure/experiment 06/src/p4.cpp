#include <iostream>
#include <queue> // For std::queue
#include <stack> // For std::stack

const int maxn = 2'000;
const int maxm = maxn * maxn;

struct vertex
{
    int head, in_degree, vis;

    vertex(int head = 0, int in_degree = 0, int vis = 0)
        : head(head), in_degree(in_degree), vis(vis)
    {
    }

    void visit()
    {
        ++vis;
    }

    bool is_fully_visited() const
    {
        return vis >= in_degree;
    }
};

struct edge
{
    int to, next;

    edge(int to = -1, int next = 0)
        : to(to), next(next)
    {
    }
};

vertex v[maxn];
edge e[maxm];
int edges;
std::stack<int> topo_order;

void bfs(int s)
{
    std::queue<int> q;
    // std::cout << s << "---\n";

    q.push(s);
    v[s].visit();

    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        topo_order.push(p);

        for (int i = v[p].head; i; i = e[i].next)
        {
            int cur = e[i].to;
            v[cur].visit();

            if (v[cur].is_fully_visited())
            {
                q.push(cur);
            }
        }
    }
}

void toposort(int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (v[i].in_degree == 0 && !v[i].vis)
        {
            bfs(i);
        }
    }
}

void clear(int n)
{
    for (int i = 0; i < n; ++i)
    {
        v[i] = vertex();
    }

    edges = 0;
}

void connect(int s, int t)
{
    e[++edges] = edge(t, v[s].head);
    v[s].head = edges;
    ++v[t].in_degree;
}

int main()
{
    int n, m;

    while (std::cin >> n >> m)
    {
        for (int i = 1; i <= m; ++i)
        {
            int s, t;
            std::cin >> s >> t;
            connect(s, t);
        }

        toposort(n);
        clear(n);

        if (topo_order.size() == n)
        {
            while (!topo_order.empty())
            {
                std::cout << topo_order.top() << ' ';
                topo_order.pop();
            }
        }
        else
        {
            std::cout << "-1";
            while (!topo_order.empty())
            {
                topo_order.pop();
            }
        }

        std::cout << std::endl;
    }
}