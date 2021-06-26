/*
You are given all numbers between 1,2,…,n except one. 
Your task is to find the missing number.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, x;
    cin>>n;
    vector <int> arr(n+1, 0);
    for(i = 1; i < n; i++)
    {
        cin>>x;
        arr[x] = x;
    }
    for(i = 1; i <= n; i++){
        if(arr[i] == 0){
            cout<<i;
            break;
        }
    }
}
