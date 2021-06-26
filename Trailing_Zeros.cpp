/*
Your task is to calculate the number of trailing zeros in the factorial n!.
For example, 20!=2432902008176640000 and it has 4 trailing zeros.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void search(ll n){
    ll c = 0;
    for(ll x = 5; n / x >= 1; x *= 5)
        c += n / x;
    cout<<c;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    search(n);
    return 0;
}
