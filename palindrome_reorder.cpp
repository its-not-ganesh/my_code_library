/*
Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string s;
  	cin >> s;
  	int alphabets[26] = {}, c1 = 0;
  	for(char d: s)
	  	++alphabets[d - 'A'];
  	for(int i = 0; i < 26; i++)
	  	c1+= alphabets[i] & 1;	//counting the odd alphabets
	if(c1 > 1){
		cout<<"NO SOLUTION";
		return 0;
	}
	
	string t;
	for(i = 0; i < 26; i++){
		if(alphabets[i]&1 ^ 1){
			for(int j = 0; j < alphabets[i]/2; i++;
				t += (char)('A' + i);
		}
	}
	cout<<t;
	for(i = 0; i < 26; i++){
		if(alphabets[i] & 1){
			for(int j = 0; j < alphabets[i]; j++)
				cout << (char)('A' + i);
		}
	}
	reverse(t.begin(), t.end());
	cout<<t;
  return 0;
}
