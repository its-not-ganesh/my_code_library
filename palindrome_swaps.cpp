#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int n = s.length();
    int count = 0, flag = 0;
    for (int i = 0; i <= n / 2; i++)
    {
        int left = i;
        int right = n - left - 1;
        cout << "first \n";
        cout << "left: " << left << ", right: " << right << endl;
        while (left < right)
        {
            if (s[left] == s[right])
                break;
            else
                right--;
        }
        if (left == right)
        {
            flag = 1;
            break;
        }
        cout << "left: " << left << ", right: " << right << endl;
        // cout << "second--> \n";

        for (int j = right; j < n - left - 1; j++)
        {

            swap(s[j], s[j + 1]);
            ++count;
        }
    }

    cout << "string: " << s << endl;

    cout << "count: ";
    if (flag == 1 && count == 0)
        cout << -1 << endl;
    else
        cout << count << endl;
    return 0;
}
