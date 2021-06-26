#include <iostream>
using namespace std;
int main() {

    long long int test_cases,N,K;
    string str;
    cin>>test_cases;
    for(int i=0;i<test_cases;i++)
    {
        long long int count=0;
        cin>>N;
        cin>>K;
        cin>>str;
        for(int j=0;j<(N/2);j++)
        {
            if(str[j]!=str[N-j-1])
            {
                if(j!= N-j-1)
                {
                    count++;
                }

            }
        }
        cout<<"Case #"<<i+1<<": "<<abs(K-count)<<"\n";


    }



    return 0;
}
