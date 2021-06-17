#include <bits/stdc++.h>

using namespace std;

int unset_bit(int num,int pos)
{
    return num&(~(1<<pos));
}

int main()
{
    cout<<unset_bit(3,1);
}