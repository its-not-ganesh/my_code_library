#include<iostream>

using namespace std;

int main()
{
    int a[100];
    int n,allno=0,arrayno=0,minn=2147483647,maxx=0;
    cin>>n;
  
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]>maxx)
        {
            maxx=a[i];
        }
        if(a[i]<minn)
        {
            minn=a[i];
        }
        arrayno = arrayno ^ a[i];
    }

    for (int i = minn; i <= maxx; i++)
    {
        allno = allno ^ i;
    }

    int ans= allno ^ arrayno;

    cout<<ans;

}