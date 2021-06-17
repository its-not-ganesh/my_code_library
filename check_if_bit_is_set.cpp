#include <bits/stdc++.h>

using namespace std;

bool check_if_bit_is_set(int num, int pos)
{
    return num&1<<pos;
}

int main()
{
    cout<<check_if_bit_is_set(3,1);
}