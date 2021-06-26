/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T.
Your task is to find the longest repetition in the sequence. 
This is a maximum-length substring containing only one type of character.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    cin>>input;
    int m, i, j;
    m = j = 1;
    for(i = 1; i<input.size(); i++){
        if(input[i] == input[i-1])
            j++;
        else
            j = 1;
        if(m < j)
            m = j;
    }
    printf("%d", m);
    return 0;
}
