#include <bits/stdc++.h>

using namespace std;

int no_of_bits_set(int num)
{
    int count=0;
    while (num)
    {
        count += num&1;
        num = num>>1;
    }
    return count;
}

int main()
{
    cout<<no_of_bits_set(5);
}