#include <iostream>

using namespace std;

int main() {
    long long int tests,num;
    cin>>tests;
    for (long long int i = 0; i < tests; i++) {
        long long int count=0,temp=0;
        cin>>num;
        temp = (2*num-1) -2;
        count = 2*num-1;
        for (long long int j = 0; j < num-1; j++) {
            count += 2*temp;
            temp -= 2;
        }
        cout<<count<<" "<<(4+(num-1)*8)<<"\n";

    }
    return 0;
}
