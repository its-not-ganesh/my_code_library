#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

void merge(ll arr[], ll l, ll mid, ll r)
{
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
        else
            arr[k++] = b[j++];
    }
    while (i < n1)
        arr[k++] = a[i++];
    while (j < n2)
        arr[k++] = b[j++];
}

void print_array(ll arr[], ll n)
{
    for (ll i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void mergeSort(ll arr[], ll l, ll r, ll n)
{
    if (l < r)
    {
        ll mid = (l + r) / 2;
        cout << "left: " << l << " right: " << r << endl;
        mergeSort(arr, l, mid, n);
        print_array(arr, n);
        mergeSort(arr, mid + 1, r, n);
        print_array(arr, n);
        merge(arr, l, mid, r);
        print_array(arr, n);
    }
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1, n);
    for (ll i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
