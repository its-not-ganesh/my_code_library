#include <bits/stdc++.h>
using namespace std;
// A given block has to be cut in such a way that its pieces product has to be maximum, what is that maximum product
// Algorithm
/*
    initialise result[len+1] array to 0
    for i <- 2 to len 
        for j <- 1 to (i/2)
            result[i] = max (result[i], 
                            j * (i-j),
                            j * result[i - j]
                            )
*/
int main()
{
    int n;
    // length of the block
    cin >> n;
    int result[n + 1];
    for (int i = 0; i < n + 1; i++)
        result[i] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= int(i / 2); j++)
        {
            int a = max(result[i], (j * (i - j)));
            result[i] = max(a, (j * result[i - j]));
        }
    }
    // maximum product
    cout << result[n];

    return 0;
}
