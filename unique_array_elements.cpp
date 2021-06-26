// Numbers are in sequential order from 1 to N. Find the unique elements in the array
#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
ll mod = 1e9 + 7;
using namespace std;
int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll temp = 0;
    for (int i = 0; i < n; i++)
        temp = temp ^ v[i];

    cout << temp << endl;
    return 0;
}
