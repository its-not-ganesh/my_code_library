#include <iostream>
#include<cmath>

using namespace std;

long long int apowerb(long long int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return (((apowerb(n/2))*(apowerb(n/2)))%1000000007);
    else
        return ( ( ((apowerb(n/2)) * (apowerb(n/2)) * 2) %1000000007 ) ); 
}
 
int main()
{
    long long int twopow,wholepow=1,T,N,M,a,b;
    cin>>T;
    for(int i = 0; i < T; i++)
    {
        cin>>N;
        cin>>M;
        twopow = apowerb(N);
        a = twopow -1;
        b = M;
        wholepow=1;
        while (b>0)
        {
            if(b%2==1)
            {
                wholepow = (wholepow*a)%1000000007;
            }
            a = (a*a)%1000000007;
            b = b/2;
             
        }
        
        cout<<wholepow<<endl;

    }
       
}

/*

Chef has two numbers N and M. Help Chef to find number of integer N-tuples (A1,A2,…,AN) such that 0≤A1,A2,…,AN≤2M−1 and A1&A2&…&AN=0, 
where & denotes the bitwise AND operator.

Since the number of tuples can be large, output it modulo 109+7.

Input
The first line contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two integers N and M.
Output
For each test case, output in a single line the answer to the problem modulo 109+7.

Constraints
1≤T≤105
1≤N,M≤106
Subtasks
Subtask #1 (100 points): original constraints

Sample Input
4
1 2
2 2
4 2
8 4
Sample Output
1
9
225
228250597
Explanation
Test Case 1: The only possible tuple is (0).

Test Case 2: The tuples are (0,0), (0,1), (0,2), (0,3), (1,0), (2,0), (3,0), (1,2), (2,1).

*/