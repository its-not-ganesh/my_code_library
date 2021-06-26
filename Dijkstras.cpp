#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // cout << "enter number of nodes: ";
    ll n, m, source;
    cin >> n;
    // cout << "enter number of edges: ";
    cin >> m;
    ll weight_matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            weight_matrix[i][j] = INT_MAX;
            if (i == j)
                weight_matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        // cout << "enter node 1, node 2, and weight: ";
        cin >> a >> b >> w;
        weight_matrix[a][b] = w;
        // cout << endl;
    }
    // cout << "enter source: ";
    cin >> source;
    // cout << "hello " << weight_matrix[5][3] << endl;

    vector<ll> dist(n), path(n);
    set<int> vertices;
    // initialisation step
    for (int i = 0; i < n; i++)
    {
        dist[i] = weight_matrix[source][i];
        path[i] = source;
        vertices.insert(i);
    }
    vertices.erase(vertices.find(source));
    set<int>::iterator itr;
    while (!vertices.empty())
    {
        // minimum_value -> minimum value of the unvisited vertex in dist array
        // u -> array index of minimum value
        ll u = INT_MAX, minimum_value = INT_MAX;

        for (itr = vertices.begin(); itr != vertices.end(); itr++)
        {
            int x = (*itr);
            if (dist[x] < minimum_value)
            {
                minimum_value = dist[x];
                u = x;
            }
        }
        // settting u as visited node
        vertices.erase(vertices.find(u));
        for (itr = vertices.begin(); itr != vertices.end(); itr++)
        {
            int x = (*itr);
            // check which path is shorter, i.e. new or prev
            // if new path is shorter then update distance and path array
            ll y = weight_matrix[u][x] + minimum_value;
            if (dist[x] > y)
            {
                dist[x] = y;
                path[x] = u;
            }
        }
    }

    cout << "dist and path " << endl;
    for (int i = 0; i < n; i++)
        cout << dist[i] << "\t" << path[i] << endl;

    return 0;
}
