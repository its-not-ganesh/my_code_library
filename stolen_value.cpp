#include <bits/stdc++.h>
using namespace std;
// A robber has to rob houses so that he has max money. He cannot steal adjacent houses.
// What is the maximum moeny he can rob?
int main()
{
    int n;
    // Number of houses
    cin >> n;
    int val[n + 1];
    val[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = 0;

    dp[1] = val[1];
    cout << endl;
    for (int i = 2; i <= n; i++)
    {
        int f = dp[i - 2] + val[i];
        dp[i] = max(dp[i - 1], f);
        cout << "i = " << i << ", adjacent house: " << dp[i - 1] << ", previous sum = " << f << endl;
        cout << "\t";

        for (int i = 0; i <= n; i++)
            cout << dp[i] << " ";
        cout << endl;
    }

    cout << "max value = " << dp[n];
    return 0;
}

/*  7 9 3 5 8 2 4 7
*/
// output = 21
