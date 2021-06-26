// All possible combinations of a given array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num[10000];
    int i, j, n, k, temp;
    cout << "Enter n: ";
    cin >> n;
    cout << "\nEnter n numbers: " << endl;
    for (i = 0; i < n; i++)
        cin >> num[i];
    cout << endl;
    for (j = 1; j <= n; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            temp = num[i];
            num[i] = num[i + 1];
            num[i + 1] = temp;
            for (k = 0; k < n; k++)
                cout << num[k] << " ";
            cout << "\n";
        }
    }

    return 0;
}
