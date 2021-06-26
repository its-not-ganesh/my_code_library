#include <bits/stdc++.h>
using namespace std;
// given an array and a sum, find whether a subset sum is equal to that sum or not.
// Algorithm :
/*
    initialise ss[i][0] = 1 and ss[0][j(1 to sum)] = 0
    for i <- 0 <= length of array
        for j <- 1 <= sum
            if(ss[i-1][j] == true)
                ss[i][j] = true
            else
                if(a[i-1] > j)
                    ss[i][j] = false
                else
                    ss[i][j] = ss[i-1][j - a[i-1]]
*/

int main()
{
    int n, sum;
    // enter the length of array and then the sum
    cin >> n >> sum;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    //i operator is the number of items
    //j operator is the sum of subset
    //ss is the table
    int ss[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        ss[i][0] = 1;
    for (int j = 1; j <= sum; j++)
        ss[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (ss[i - 1][j] == 1)
                ss[i][j] = 1;
            else
            {
                if (a[i - 1] > j)
                    ss[i][j] = 0;
                else
                    ss[i][j] = ss[i - 1][j - a[i - 1]];
            }
        }
    }

    cout << endl
         << "dp Table: " << endl;
    for (int j = 0; j <= sum; j++)
        cout << j << " ";
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
            cout << ss[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i <= n; i++)
    {
        if (ss[i][sum] == 1)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
