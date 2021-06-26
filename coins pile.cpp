/*
You have two coin piles containing a and b coins. 
On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.
Your task is to efficiently find out if you can empty both the piles.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t, a, b;
    cin>>t;
    vector<int> sol(t, 0);

    for(ll i = 0; i < t; i++){
        cin>> a >> b;
        if(2 * a - b >= 0 && (2 * a - b) % 3 == 0 && 2 * b - a >= 0 && (2 * b - a) % 3 == 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

