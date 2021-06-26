/*
Your task is to count for k=1,2,…,n the number of ways two knights can be placed on a k×k chessboard so that they do not attack each other.
*/
#include<bits/stdc++.h>
using namespace std;
long long binomialCoeff(long long n, long long k)
{
    long long res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
 
    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
 
void search(long long n){
    long long c = 0;
    if(n == 1 || n == 0){
        cout<<c;
        return;
    }
    for(long long i = 1; i <= n; i++){
        if(i == 1)
            cout<<c<<"\n";
        else{ // Here I am removing the number of 2x3 and 3x2 matrices formed in the board from the total number 
              // of ways you can place the two knights
            c = binomialCoeff(i*i, 2) - (4 * (i -2) * (i - 1));
            cout<<c<<"\n";
        }
    }
}

int main(){
    long long x;
    cin>>x;
    search(x);
    return 0;
}
