/*
Your task is to divide the numbers 1,2,…,n into two sets of equal sum.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum(ll n){
    if(n <= 1)
        return 1;
    return sum(n-1) + n;
}
void solve(ll n, ll s){
    vector<ll> arr(n+1, 0);
    ll c = 0;
    while(n > 0){
        if(s - n >= 0){
           s = s - n;
           arr[n] = 1;
           c++;
        }
        n--;
    }
    cout<<c<<"\n";
    for(ll i = arr.size() - 1; i > 0; i--){
        if(arr[i] == 1)
            cout<<i<<" ";
    }
    cout<<"\n"<<(arr.size() - c - 1)<<"\n";
    for(ll i = arr.size() - 1; i > 0; i--){
        if(arr[i] == 0)
            cout<<i<<" ";
    }
 
}
 
int main(){
    ll n;
    cin>>n;
    ll s = sum(n);
    if(s % 2 == 0){
        cout<<"YES\n";
        solve(n, s/2);
    }
    else
        cout<<"NO";
    return 0;
}
