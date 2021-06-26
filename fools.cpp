#include <iostream>
#include <vector>

using namespace std;

int main() {
    int fools,typefools;
    string s,finds;
    vector<string> stringfull;
    vector<string>::iterator it;
    cin>>fools;
    for (int i = 0; i < fools; i++) {
        cin>>s;
        stringfull.push_back(s);
    }
    int count=0;
    cin>>typefools;

    for (int i = 0; i < typefools; i++) {
        cin>>finds;
        count=0;
        for(it = stringfull.begin();it!=stringfull.end();it++)
        {

            if(*it==finds)
            {
                count++;
            }
        }
        cout<<count<<"\n";

    }
    return 0;
}
