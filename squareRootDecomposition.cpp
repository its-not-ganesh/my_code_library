#include <bits/stdc++.h>
// #define int long long
using namespace std;

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int blockSize = sqrt(n);
    int b1 = blockSize + 1;
    int sqrtDecom[b1];
    for (int i = 0; i <= blockSize; i++)
    {
        int minimum = INT_MAX;
        for (int j = 0; j < blockSize; j++)
        {
            int l = (i * blockSize) + j;
            if (l == n)
                break;
            minimum = min(minimum, arr[l]);
        }
        sqrtDecom[i] = minimum;
    }

    for (int i = 0; i < m; i++)
    {
        int l, r, minimum = INT_MAX;
        scanf("%d %d", &l, &r);
        int diff = l - r;
        int sq_l = l / blockSize;
        int sq_r = r / blockSize;
        if (l == r)
        {
            printf("%d\n", arr[l]);
            continue;
        }
        else if (l % blockSize == 0 && r % blockSize == 1)
        {
            for (int j = sq_l; j <= sq_r; j++)
                minimum = min(minimum, sqrtDecom[j]);
            printf("%d\n", minimum);
            continue;
        }
        else if (sq_l == sq_r)
        {
            for (int j = l; j <= r; j++)
                minimum = min(minimum, arr[j]);
            printf("%d\n", minimum);
            continue;
        }
        else
        {
            int l_limit = (sq_l + 1) * blockSize;
            int r_limit = sq_r * blockSize;
            for (int j = l; j < l_limit; j++)
                minimum = min(minimum, arr[j]);
            for (int j = sq_l + 1; j < sq_r; j++)
                minimum = min(minimum, sqrtDecom[j]);
            for (int j = r_limit; j <= r; j++)
                minimum = min(minimum, arr[j]);

            printf("%d\n", minimum);
            continue;
        }
    }

    return 0;
}
