#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, res = "";
    cin >> s;
    int x = 32;
    for (int i = 0; i < s.length(); i++)
        res += char((int(s[i]) | x));
    cout << res;
    return 0;
}
