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
    ll n, a, x;
    // 5 2 1
    cin >> n >> a >> x;
    ll ones = n - a;
    ll zeros = a;
    if (x > ones * zeros)
    {
        cout << "-1";
        return 0;
    }
    vector<char> v;
    for (int i = 0; i < n; i++)
    {
        if (i < a)
            v.push_back('0');
        else
            v.push_back('1');
    }
    ll last = n - 1;
    ll zeros_pos = a - 1;
    ll quo = x / ones;
    ll rem = x % ones;
    for (ll i = 0; i < quo; i++)
        swap(v[zeros_pos--], v[last--]);
    swap(v[zeros_pos], v[zeros_pos + rem]);
    for (auto i : v)
        cout << i << " ";
    return 0;
}
