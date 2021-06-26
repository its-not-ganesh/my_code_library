/*
A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.
*/
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n, i;
    cin>>n;
    if(n == 1){
        cout<<n;
        return 0;
    }
    if(n < 4){
        printf("NO SOLUTION");
        return 0;
    }
    for(i = 2; i <= n; i = i + 2)
        cout<<i<<" ";
    for(i = 1; i <= n; i = i + 2)
        cout<<i<<" ";
    return 0;
}
