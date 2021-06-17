#include <bits/stdc++.h>

using namespace std;

int set_a_bit(int num, int pos)
{
    return num|1<<pos;
}

int main()
{
    cout<<set_a_bit(5,1);
}