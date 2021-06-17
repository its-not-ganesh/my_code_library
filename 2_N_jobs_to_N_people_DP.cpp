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

int set_a_bit(int num, int pos)
{
    return num|1<<pos;
}

bool check_if_bit_is_set(int num, int pos)
{
    return num&1<<pos;
}

int unset_bit(int num,int pos)
{
    return num&(~(1<<pos));
}

int calculate_min_cost()
{
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int ln=pow(2,n);
    int dp[ln];
    dp[0]=0;
    for(int i=1;i<ln;i++)
    {
        dp[i]=INT_MAX;
    }
    int m,o;
    for(int i=0;i<ln;i++)
    {
        int x=no_of_bits_set(i);
        for(int j=0; j<n;j++)
        {
            if(!check_if_bit_is_set(i,j))
            {
                m=dp[set_a_bit(i,j)];
                o=dp[i]+arr[x][j];
                dp[set_a_bit(i,j)]=min(m,o);
            }
        }
    }
    cout<<"\nAnswer:"<<dp[ln-1];
}

int main() {

    //cout<<no_of_bits_set(3);
    //cout<<unset_bit(7,1);
    calculate_min_cost();
    return 0;

}
