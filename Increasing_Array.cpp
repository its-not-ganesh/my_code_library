/*
You are given an array of n integers. 
You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. What is the minimum number of moves required?
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    long long m = 0, n, i, diff;
    cin>>n;
    long long x[n];
    for(i = 0; i < n; i++){
        cin>>x[i];
    }

    for(i = 0; i < n - 1; i++){
        if(x[i] > x[i+1]){
                diff = x[i] - x[i+1];
            m+= diff;
            x[i+1] += diff;
        }
    }
    cout<<m;
}
