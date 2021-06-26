/*
There are n apples with known weights. 
Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ways = 0;
bool reserve[8][8], col[16], diag1[16], diag2[16];
void search(ll r){
	if(r == 8){
		ways++;
		return;
	}
	for(int c = 0; c < 8; ++c){
		if(col[c] || diag1[r+c] || diag2[r-c+7] || reserve[r][c])
			continue;
		col[c] = diag1[r+c] = diag2[r-c+7] = true;
			search(r++);
		col[c] = diag1[r+c] = diag2[r-c+7] = false;
	}
}

int main(){
	string s;
	for(int i = 0; i < 8; i++)
	{
		cin >> s;
		col[i] = diag1[i] = diag2[i] = false;
		for(int j = 0; j < 8; j++)
			reserve[i][j] = s[j] != '.';
	}
	search(0);
	cout<<ways;
}
