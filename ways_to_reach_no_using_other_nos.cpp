#include<iostream>

using namespace std;

/*
    arr[15] is no of ways 15 can be reached by adding 3s,5s,10s
    arr 1 0 0 1 0 1 1 0 1 1 2  1  1  3  1  3
    ind 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/

int main()
{
    int arr[20],num;
    cin>>num;
    for (int i = 0; i < num+1; i++)
    {
        arr[i]=0;
    }
    arr[0]=1;
    cout<<"GG";
    for (int i = 3; i < num+1; i++)
    {
        arr[i]=arr[i]+arr[i-3];
    }
    for (int i = 5; i < num+1; i++)
    {
        arr[i]=arr[i]+arr[i-5];
    }
    for (int i = 10; i < num+1; i++)
    {
        arr[i]=arr[i]+arr[i-10];
    }
    cout<<arr[15];
    
}