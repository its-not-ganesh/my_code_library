#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    int n,max=0,max2=0,m;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>m;
        if(m>max2&&m<max)
        {
            max2=m;
        }
        else if(m>max)
        {
            max2=max;
            max=m;
        }
    }
    cout<<max2;
    return 0;
}
