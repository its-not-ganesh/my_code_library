/*
A number spiral is an infinite grid whose upper-left square has number 1.
https://cses.fi/problemset/task/1071
Your task is to find out the number in row y and column x.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll y, ll x){
    //y -> rows && x -> columns
    if(x == y ) //diagonals
        return (y*y - ( x - 1));
 
    if(y % 2 == 0 && x == 1) //even rows
        return y * y;
 
    if(x%2 != 0 && y == 1) //odd columns
        return x * x;
 
    if(y % 2 != 0 && x < y) //5,6; 17, 18, 19, 20 odd rows
        return ((y - 1) * (y - 1)) + x;
 
    if(x % 2 == 0 && y < x) //2; 10, 11, 12
        return ((x - 1) * (x - 1)) + y;
 
    if(y%2 == 0 && x < y) //15, 14
        return (y*y) - (x - 1);
 
    if(x%2 != 0 && y < x) // 24, 23, 22
        return (x*x) - (y - 1);
 
    return 0;
}
 
int main(){
    ll x, y, n;
    cin>>n;
    vector<ll> solution(n);
    //row -> y && col -> x
    for(ll i = 0; i < n; i++){
        cin>>y>>x;
        solution[i] = solve(y, x);
    }
    for(ll i = 0; i < n; i++)
        cout<<solution[i]<<"\n";
    
