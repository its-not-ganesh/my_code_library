#include <bits/stdc++.h>
using namespace std;

int bin_coeff(int n, int k)
{
    int c[k + 1];
    memset(c, 0, sizeof(c));
    c[0] = 1;
    int i, j;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
            c[j] = c[j] + c[j - 1];
    }

    for (int i = 0; i <= k; i++)
        cout << c[i] << " ";

    cout << endl;
    return c[k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << bin_coeff(n, k);
    return 0;
}
