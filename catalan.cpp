#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
// Used in mountain ranges, matching parenthesis, given n keys how many binary search trees can you construct, DYCK's path
// Recursive method of catalan numbers
// ll catalan(ll n)
// {
//     if (n <= 1)
//         return 1;
//     ll res = 0;
//     for (int i = 0; i < n; i++)
//         res += catalan(i) * catalan(n - i - 1);
//     return res;
// }

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    ll dp[t + 1], arr[t];
    for (ll i = 0; i < t; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i <= t; i++)
        dp[i] = 0;
    dp[0] = 1;
    for (ll i = 0; i <= t; i++)
    {
        for (ll j = 0; j < i; j++)
        {
            dp[i] += dp[i - j - 1] * dp[j];
        }
    }

    for (ll i = 0; i <= t; i++)
        cout << dp[i] << " ";
    return 0;
}
