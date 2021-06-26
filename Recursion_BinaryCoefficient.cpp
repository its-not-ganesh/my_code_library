#include <bits/stdc++.h>
using namespace std;
int binCoeff(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return binCoeff(n - 1, k - 1) + binCoeff(n - 1, k);
}
int main()
{
    cout << "N c K \n";
    int n, k;
    cin >> n >> k;
    cout << binCoeff(n, k);
}
