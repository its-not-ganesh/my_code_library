#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

ll kadaneAlgorithm(ll arr[], ll n, ll &start, ll &end)
{
    ll sum = 0, max_sum = INT_MIN;
    end = -1;
    ll tempStart = 0;

    for (ll i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            tempStart = i + 1;
        }
        else if (sum > max_sum)
        {
            max_sum = sum;
            start = tempStart;
            end = i;
        }
    }

    if (end != -1)
        return max_sum;
    max_sum = arr[0];
    start = end = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] > max_sum)
        {
            max_sum = arr[i];
            end = start = i;
        }
    }
    return max_sum;
}

void maxSumRect()
{
    ll maxSum = INT_MIN, endLeft, endRight, endTop, endBottom;

    ll left, right, row, column;

    ll sum, start, end;

    cin >> row >> column;
    ll temp[row];
    ll matrix[row][column];
    for (ll i = 0; i < row; i++)
        for (ll j = 0; j < column; j++)
            cin >> matrix[i][j];

    for (left = 0; left < column; left++)
    {
        for (ll i = 0; i < row; i++)
            temp[i] = 0;

        for (right = left; right < column; right++)
        {
            for (ll i = 0; i < row; i++)
                temp[i] += matrix[i][right];
            sum = kadaneAlgorithm(temp, row, start, end);

            if (sum > maxSum)
            {
                maxSum = sum;
                endLeft = left;
                endRight = right;
                endBottom = end;
                endTop = start;
            }
        }
    }

    ll newSum = 0;
    for (ll i = endTop; i <= endBottom; i++)
    {
        for (ll j = endLeft; j <= endRight; j++)
        {

            if (matrix[i][j] > 0)
            {
                newSum += matrix[i][j];
            }
        }
    }

    cout << maxSum << endl
         << newSum << endl;
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    maxSumRect();
    return 0;
}
