#include <iostream>
#include <vector>

#include <sstream>
#include <string>

using namespace std;

int main() {
    int fools,typefools;
    string s,finds;
    vector<string> stringfull;
    vector<string>::iterator it;
    cin>>fools;

    int count=0;
    string allwords;
    getline( cin, allwords );

// Parse words into a vector

    string word;
    istringstream iss(allwords);
    while( iss >> word ) stringfull.push_back(word);


    for (int i = 0; i < typefools; i++) {
        cin>>finds;
        count=0;
        int flag =0;
        for(it = stringfull.begin();it!=stringfull.end();it++)
        {

            string ss=*it;
            cout<<ss<<" ";
            if(flag == 0)
            {
                for (int j = 0; j < finds.size(); j++) {

                    if(ss[j]==finds[j])
                    {
                        count++;
                    }

                }
                if(count==finds.size()-1||count==finds.size())
                {
                    flag =1;
                    break;
                }
            }
            else
            {
                break;
            }


        }
        if(count==finds.size()-1||count==finds.size())
        {
            cout<<"YES\n";
        } else{
            cout<<"NO\n";
        }


    }
    return 0;
}
