#include <bits/stdc++.h>
using namespace std;
// subsequence -> abc is a subsequence of abacd but its not a substring.
// we have to find the longest common subsequence of two strings
// we create a DP matrix, where each side is the length of one string
// we initialize 0 column and row to 0 because there will be nothing common with an empty string

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length();
    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= len2; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
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

    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return 0;
}
