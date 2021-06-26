#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

ll merge(ll arr[], ll l, ll mid, ll r)
{
    ll inv = 0;
    ll n1 = mid - l + 1;
    ll n2 = r - mid;
    ll a[n1], b[n2];
    for (ll i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (ll i = 0; i < n2; i++)
        b[i] = arr[i + mid + 1];

    ll i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            arr[k++] = a[i++];
        else if (a[i] >= b[j])
        {
            arr[k++] = b[j++];
            inv += n1 - i;
        }
        if (a[i] == b[j])
        {
            inv -= 1;
            if (inv < 0)
                inv = 0;
            arr[k++] = a[i++];
        }
    }
    while (i < n1)
        arr[k++] = a[i++];
    while (j < n2)
        arr[k++] = b[j++];
    // cout << "\t";
    // for (ll i = l; i <= r; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
    // cout << "\t\tinversions = " << inv << endl;

    return inv;
}

ll mergeSort(ll arr[], ll l, ll r)
{
    ll inv = 0;
    if (l < r)
    {
        ll mid = (l + r) / 2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}
int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll count = mergeSort(arr, 0, n - 1);
        cout << count << endl;
        if (count >= n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
