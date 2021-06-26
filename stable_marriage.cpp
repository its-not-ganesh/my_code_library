#include <bits/stdc++.h>
using namespace std;
// stable marriage problem

/*
        ann  lea  sue
    bob 2,3  1,2  3,3
    jim 3,1  1,3  2,1
    tom 3,2  2,1  1,2
*/

// QUESTION->
// bob's 2nd preference is ann and ann's 3rd preference is bob.
// boy proposes to a girl and if the boy has higher preference than her current BF she will accept the boy else reject him.
// find the most stable marriage configuration

// Explaination->
// in first step, bob proposes to lea becuase she is his first preference and she accepts because she isn't with anyone

// in second step, jim proposes to lea but she rejects because jim is lea's third preference and she is already committed to bob who is her 2nd preference. So jim proposes to sue who is his 2nd preference and sue accepts because jim is her first preference.

// in third step, tom proposes to sue but she is already committed to her 1st preference. So tom proposes to lea who is his 2nd preference and she accepts because tom is her 1st preference and leaves bob.

// Bob is now the free man so, bob proposes to his 2nd preference ann and she accepts him becuase she isn't committed to anyone
int main()
{
    int n = 3;
    int male[n][n] = {{2, 1, 3}, {3, 1, 2}, {3, 2, 1}};
    // female has been written in the opposite direction i.e horizontally instead of vertical because its easier to code.
    int female[n][n] = {{3, 2, 3}, {1, 3, 1}, {2, 1, 2}};
    int freemen[n], freewomen[n];

    int count = 0;
    // initialising
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> male[i][j];
            male[i][j] -= 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // weird way input
            cin >> female[j][i];
            female[j][i] -= 1;
            // direct input
            // cin >> female[i][j];
            // female[i][j] -= 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        freemen[i] = -1;
        freewomen[i] = -1;
    }
    //main logic
    while (count != n)
    {
        for (int i = 0; i < n; i++)
        {
            // if man is free
            if (freemen[i] == -1)
            {
                cout << "\t man : " << i << endl;

                // check his highest preference
                int highPref = 0;
                while (freemen[i] == -1)
                {
                    int j;

                    for (j = 0; j < n; j++)
                    {
                        if ((male[i][j]) == highPref)
                            break;
                    }
                    // cout << "\t\t\t\ti = " << i << " j = " << j << endl;
                    cout << "\t\t highest preference is woman " << j << endl;
                    cout << "\t\t\t woman status " << freewomen[j] << endl;
                    cout << "\t\t\t woman pref of this man: " << (female[j][i]) << endl;

                    if (freewomen[j] == -1)
                    {
                        cout << "\t\t\t\t WOMAN NOT TAKEN " << endl;
                        freemen[i] = j;
                        freewomen[j] = i;
                    }
                    else if (female[j][freewomen[j]] > female[j][i])
                    {
                        cout << "\t\t\t\t WOMAN EXCHANGED" << endl;
                        // cout << "\t\t\t\t "
                        freemen[i] = j;
                        freemen[freewomen[j]] = -1;
                        freewomen[j] = i;
                    }
                    else
                        highPref += 1;
                }
            }
        }

        // check if every one is committed
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (freemen[i] == -1)
                break;
            else
                count += 1;
        }
    }

    for (int i = 0; i < n; i++)
        cout << "man " << i + 1 << " with woman " << freemen[i] + 1 << endl;
    return 0;
}

/*
    input ->
    n, men pref, women pref
    3

    2 1 3
    3 1 2
    3 2 1
    // in case woman's pref is given in opposite way like in above example
    3 2 3
    1 3 1 
    2 1 2
    // in case woman's pref is given directly
    3 1 2
    2 3 1 
    3 2 1
*/
