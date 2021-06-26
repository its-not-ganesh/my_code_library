/*
Your task is to calculate the number of bit strings of length n.
For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod (ll)(1e9 + 7)

ll power(ll x, ll y, ll p){
    ll res = 1;
    x = x % p; // this is to make the big number smaller because x can become really big
    while(y > 0){
        if(y & 1) // if y is odd, multiply x with the result
            res = (res * x) % p; //doing modulus with mod 
        y = y >> 1; // y = y / 2
        x = (x * x) % p; // x  = x ^ 2
    }
    return res;
}

int main(){
    ll n;
    cin >> n;
    cout<<power(2, n, mod);
    return 0;
}
