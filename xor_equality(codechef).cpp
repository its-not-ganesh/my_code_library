#include <iostream>
#include<cmath>

using namespace std;

unsigned long long int fastspcexp(unsigned long long int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return (((fastspcexp(n/2))*(fastspcexp(n/2)))%1000000007);
    else
        return ( ( ((fastspcexp(n/2)) * (fastspcexp(n/2)) * 2) %1000000007 ) ); 
}
 
int main()
{
    unsigned long long int T,N;
    cin>>T;
    for(int i = 0; i < T; i++)
    {
        cin>>N;
        cout<<fastspcexp(N-1)<<endl;

    }
       
}

/*

For a given N, find the number of ways to choose an integer x from the range [0,2N−1] such that x⊕(x+1)=(x+2)⊕(x+3), where ⊕ 
denotes the bitwise XOR operator.

Since the number of valid x can be large, output it modulo 109+7.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
The only line of each test case contains a single integer N.
Output
For each test case, output in a single line the answer to the problem modulo 109+7.

Constraints
1≤T≤105
1≤N≤105
Subtasks
Subtask #1 (100 points): Original Constraints

Sample Input
2
1
2
Sample Output
1
2
Explanation
Test Case 1: The possible values of x are {0}.

Test Case 2: The possible values of x are {0,2}.
*/