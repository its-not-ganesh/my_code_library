#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

void show(vector<Edge> edges, int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << "node1: " << edges[i].u << " node2: " << edges[i].v << " weight: " << edges[i].weight << endl;
    }
}

void details(Edge e, int x, int y)
{
    cout << "node1: " << e.u << " node2: " << e.v << " weight: " << e.weight << endl;
    cout << "\t belongs to tree x: " << x << " and y: " << y << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges, result;
    for (int i = 0; i < m; i++)
    {
        Edge e;
        int u, v, weight;
        cin >> u >> v >> weight;
        e.u = u - 1;
        e.v = v - 1;
        e.weight = weight;
        edges.push_back(e);
    }
    sort(edges.begin(), edges.end());
    // cout << "all edges: " << endl;
    // show(edges, m);
    vector<int> tree_id(n);
    int cost = 0;
    for (int i = 0; i < n; i++)
        tree_id[i] = i;
    for (Edge e : edges)
    {
        // details(e, tree_id[e.u], tree_id[e.v]);
        if (tree_id[e.u] != tree_id[e.v])
        {
            cost += e.weight;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++)
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
        }
    }
    // cout << "final tree: " << endl;
    // show(result, m);
    // cout << "sum = " << cost << endl;
    cout << cost;
    return 0;
}
