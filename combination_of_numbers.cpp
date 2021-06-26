#include <bits/stdc++.h>
using namespace std;
// Find the number of ways to reach 'x' using n1, n2, n3 and nN numbers
// Ex: find the number of ways to reach 15 using 3s, 5s, and 10s.
// We use Dynamic Programming, where the dp table consists of all the numbers upto 'x'
//  we initialise the first element 0 to 1 and its logic is that no way is also a way.
int main()
{
    int sum, n;
    cin >> n >> sum;
    int a[n], res[sum + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i <= sum; i++)
        res[i] = 0;
    res[0] = 1;

    cout << endl
         << "DP table: ";
    for (int i = 0; i <= sum; i++)
        cout << res[i] << " ";

    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= sum; j++)
        {
            res[j] += res[j - a[i]];
        }
        cout << endl
             << "DP table: ";
        for (int i = 0; i <= sum; i++)
            cout << res[i] << " ";
    }

    cout << endl
         << "max combinations: " << res[sum];
    return 0;
}
