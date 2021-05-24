#include<iostream>

using namespace std;

bool isPrime(long long int n)
{

    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (long long int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

int main()
{
    long long int a=1000000007;
    bool g=isPrime(a);
    cout<<g;
}