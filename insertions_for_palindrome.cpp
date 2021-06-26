#include <bits/stdc++.h>
using namespace std;
// we follow the same method as longest_subsequence but here we just reverse the string and compare with itself

int main()
{
    string s1, s2;
    cin >> s1;
    s2 = s1;
    int len = s1.length();
    for (int i = 0; i < len; i++)
        s2[i] = s1[len - i - 1];
    int dp[len + 1][len + 1];

    for (int i = 0; i <= len; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= len; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
            // dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << endl
         << "DP matrix: " << endl;

    for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j <= len; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    cout << "insertions required: " << len - dp[len][len] << endl;
    return 0;
}
