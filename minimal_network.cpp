#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

int main() {
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
