#include <bits/stdc++.h>
using namespace std;
// This is sparse table pre-processing.
void show(int arr[50][50], int m, int n)
{
    cout << "sparse table: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "----------------------------" << endl;
}

void x();
int main()
{
    x();
    return 0;
}

void x()
{

    int lookup[50][50];
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            lookup[i][j] = -1;
    int a[] = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    int n = 9, i, j;
    for (int i = 0; i < n; i++)
        lookup[i][0] = i;

    cout << "initializing values: " << endl;
    show(lookup, n, 1);
    for (j = 1; (1 << j) <= n; j++)
    {
        cout << "\t first loop condition: " << (1 << j) << " <= " << n << endl;
        for (i = 0; (i + (1 << j) - 1) < n; i++)
        {
            int f1 = i + (1 << (j - 1));
            cout << "\t\t second loop condition: " << a[lookup[i][j - 1]] << " < " << a[lookup[i + (1 << (j - 1))][j - 1]] << endl;
            cout << "\t\t a[" << lookup[i][j - 1] << "] and a[" << lookup[i + (1 << (j - 1))][j - 1] << "]" << endl;
            if (a[lookup[i][j - 1]] < a[lookup[i + (1 << (j - 1))][j - 1]])
            {
                lookup[i][j] = lookup[i][j - 1];
                cout << "\t\t\t lookup(" << i << "," << j << ") = ";
                cout << "lookup(" << i << ", " << j - 1 << ") = ";
                cout << lookup[i][j] << endl;
            }

            else
            {
                lookup[i][j] = lookup[f1][j - 1];
                cout << "\t\t\t row position = " << i << " + (1 << (" << j << " - 1) = " << f1 << endl;
                cout << "\t\t\t lookup(" << i << "," << j << ") = ";
                cout << "lookup(" << f1 << ", " << (j - 1) << ") = ";
                cout << lookup[i][j] << endl;
            }
        }
        show(lookup, n, j + 1);
    }
}
