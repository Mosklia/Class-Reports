#include <iostream>
#include <algorithm>
#include <queue> // For std::queue

const int inf = 0X3F3F3F3F; // Infinity.
const int maxm = 100'000; // Maximum number of edges.
const int maxn = 100'000; // Maximum number of vertices.

struct edge
{
    int to;
    edge *next;

    /**
     * @brief Construct a new edge
     * 
     * @param t The ending vertex of the edge.
     * @param n The next edge comes out from vertex t.
     */
    edge(int t = 0, edge* n = nullptr)
    : to(t), next(n)
    {
    }
};

struct vertex
{
    int dist; // Distance to the starting vertex.
    edge *head; // First edge that comes out from this.

    /**
     * @brief Construct a new vertex
     * Note that a new vertex's distance is always infinity.
     * You should change this after the constrcution.
     * 
     * @param h First edge comes out from the vertex.
     */
    vertex(edge *h = nullptr)
    : dist(inf), head(h)
    {
    }
};

edge e[maxm];
vertex v[maxn];

/**
 * @brief Reset the graph.
 * Remove everything in the graph.
 * 
 */
void clear()
{
    for (auto &x : e)
    {
        x = edge();
    }

    for (auto &x : v)
    {
        x = vertex();
    }
}

/**
 * @brief Do BFS from a given vertex.
 * 
 * @param s The given source vertex.
 */
void bfs(int s)
{
    std::queue<int> q; // BFS sequence

    // The distance between s and itself is -.
    v[s].dist = 0;

    // Start the BFS from vertex s.
    q.push(s);

    // BFS loop
    while (!q.empty())
    {
        int p = q.front(); // The currently using vertex
        q.pop();

        // Vertices after p
        for (edge *i = v[p].head; i; i = i->next)
        {
            int cur = i->to;

            // Vertex cur is not visited.
            if (v[cur].dist == inf)
            {
                // Search cur.
                q.push(cur);

                // Update the distance.
                // Note that all the edge has a fixed length 1
                v[cur].dist = v[p].dist + 1;
            }
        }
    }
}

int main()
{
    int n, m;

    while (std::cin >> n >> m)
    {
        for (int i = 0; i < m; ++i)
        {
            int s, t;
            std::cin >> s >> t;

            // Add the edge.
            e[i] = edge(t, v[s].head);
            
            // Update the head.
            v[s].head = e + i;
        }

        bfs(1);

        std::cout << (v[n].dist >= inf ? -1 : v[n].dist) << std::endl;

        for (int i = 1; i <= n; ++i)
        {
            v[i] = vertex();
        }

        for (int i = 0; i < m; ++i)
        {
            e[i] = edge();
        }
    }
}