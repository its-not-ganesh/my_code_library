#include <iostream>

using namespace std;
 

int main()
{
    int arr[1000000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int max_so_far = 0;
    int max_ending_here = 0;
    int start = 0, end = 0;
    int beg = 0;

    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];

        if (max_ending_here < 0)
        {
            max_ending_here = 0;    
            beg = i + 1;
        }
 
       
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = beg;
            end = i;
        }
    }
 
    cout << max_so_far << endl;
    int newarr[1000000];
    int j=0;
 
    for (int i = 0; i <= start; i++) {
        newarr[j] = arr[i];
        j++;
    }
    for (int i = start+1; i <= end; i++) {
        newarr[j] = arr[i];
        j++;
    }

    n= n-(end-start+1);
    max_so_far = 0;
    max_ending_here = 0;
    start = 0, end = 0;
    beg = 0;

    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + newarr[i];

        if (max_ending_here < 0)
        {
            max_ending_here = 0;    
            beg = i + 1;
        }
 
       
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = beg;
            end = i;
        }
    }
 
    cout << max_so_far << endl;

    
 
    return 0;
}