// playing with strings
/*
Sam played holi with red, yellow, green, blue, etc. colors. 
His holi was cheerful and has been sleep-talking about the day.
A lot of it is gibberish. Find out which colors did Sam mention in his sleep talk.
Sam has been prouncing colors with at-most one spelling mistake.

i/p->
18
i played with flue
2
red
blue
o/p->
NO
YES
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int l, q, count = 0;
    cin >> l;
    string str = "";
    vector<string> querries, inputs;
    while (count <= l)
    {
        cin >> str;
        inputs.push_back(str);
        count += str.length() + 1;
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> str;
        querries.push_back(str);
    }

    for (int i = 0; i < q; i++)
    {
        int flag = 0;
        for (int j = 0; j < inputs.size(); j++)
        {
            if (querries[i].length() == inputs[j].length())
            {
                int len = inputs[j].length();
                int c = 0;
                string s1 = querries[i];
                string s2 = inputs[j];
                for (int k = 0; k < len; k++)
                    if (s1[k] == s2[k])
                        c++;

                if (c + 1 >= len)
                {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
            cout << "NO" << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
