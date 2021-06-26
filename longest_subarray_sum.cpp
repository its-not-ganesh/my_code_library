#include <bits/stdc++.h>
using namespace std;
//longest sub array sum
//Also known as Kadane's algorithm

int main()
{
    int n, max = 0, tmax = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        tmax += a[i];
        if (tmax < 0)
            tmax = 0;
        if (max < tmax)
            max = tmax;
    }

    cout << max;
    return 0;
}
