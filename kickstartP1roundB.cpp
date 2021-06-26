#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t, r, c;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> r >> c;
        int m[r][c];
        for (int j = 0; j < r; j++)
            for (int k = 0; k < c; k++)
                cin >> m[j][k];
        int l_counter = 0;

        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                //L-1
                int j1=j,k1=k;

                if (m[j1][k1] == 1 && m[j1 + 1][k1] == 1 && m[j1][k1 + 1]&&j1!=r&&k1!=c)
                {
                    int horizontal = 1, vertical = 1;
                    //length of horizontal segment
                    while (m[j1][k1 + 1] == 1 && k1 <= c)
                    {
                        horizontal++;
                        k1++;
                    }
                    j1=j;
                    k1=k;
                    //length of vertical segment
                    while (m[j1 + 1][k1] == 1 && j1 <= r)
                    {
                        vertical++;
                        j1++;
                    }
                    int d1 = max(vertical, horizontal);
                    int d2 = min(vertical, horizontal);

                    int m=min(vertical,horizontal);

                    for(int p=2;p<m+1;p++)
                    {
                        if(p<=vertical&&p*2<=horizontal)
                            l_counter++;
                        if(p*2<=vertical&&p<=horizontal)
                            l_counter++;
                    }

                }
                //L-2
                j1=j;
                k1=k;
                if (m[j1][k1] == 1 && m[j1 + 1][k1] == 1 && m[j1][k1 - 1]==1&&j1!=r&&k1!=0)
                {
                    int horizontal = 1, vertical = 1;
                    while (m[j1][k1 - 1] == 1 && k1 >= 0)
                    {
                        horizontal++;
                        k1--;
                    }
                    j1=j;
                    k1=k;
                    //length of vertical segment
                    while (m[j1 + 1][k1] == 1 && j1 <= r)
                    {
                        vertical++;
                        j1++;
                    }

                    int m=min(vertical,horizontal);

                    for(int p=2;p<m+1;p++)
                    {
                        if(p<=vertical&&p*2<=horizontal)
                            l_counter++;
                        if(p*2<=vertical&&p<=horizontal)
                            l_counter++;
                    }
                }
                //L-3
                j1=j;
                k1=k;
                if (m[j1][k1] == 1 && m[j1 - 1][k1] == 1 && m[j1][k1 + 1]==1&&k1!=c&&j1!=0)
                {
                    int horizontal = 1, vertical = 1;
                    while (m[j1][k1 + 1] == 1 && k1 <= c)
                    {
                        horizontal++;
                        k1++;
                    }
                    j1=j;
                    k1=k;
                    //length of vertical segment
                    while (m[j1 - 1][k1] == 1 && j1 >= 0)
                    {
                        vertical++;
                        j1--;
                    }
                    int m=min(vertical,horizontal);

                    for(int p=2;p<m+1;p++)
                    {
                        if(p<=vertical&&p*2<=horizontal)
                            l_counter++;
                        if(p*2<=vertical&&p<=horizontal)
                            l_counter++;
                    }
                }
                //L-4
                if (m[j1][k1] == 1 && m[j1 - 1][k1] == 1 && m[j1][k1 - 1]==1&&j1!=0&&k1!=0)
                {
                    int horizontal = 1, vertical = 1;
                    while (m[j1][k1 - 1] == 1 && k1 >= 0)
                    {
                        horizontal++;
                        k1--;
                    }
                    j1=j;
                    k1=k;
                    //length of vertical segment
                    while (m[j1 - 1][k1] == 1 && j1 >= 0)
                    {
                        vertical++;
                        j1--;
                    }
                    int m=min(vertical,horizontal);

                    for(int p=2;p<m+1;p++)
                    {
                        if(p<=vertical&&p*2<=horizontal)
                            l_counter++;
                        if(p*2<=vertical&&p<=horizontal)
                            l_counter++;
                    }
                }
            }
        }
        cout << "Case #" << i + 1 << ": " << l_counter << endl;
    }
    return 0;
}