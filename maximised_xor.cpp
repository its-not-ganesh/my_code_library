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
    ll l, r;
    cin >> l >> r;
    ll temp = l ^ r;
    ll res = 1;
    while (temp)
    {
        temp = temp >> 1;
        result = result << 1;
    }
    cout << (result - 1) << endl;
    return 0;
}
