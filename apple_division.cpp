/*
There are n apples with known weights.
Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, p[20];
int main(){
	ll s = 0, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> p[i], s += p[i];
	for(int i = 0; i < 1 << n; i++){ //this iterates through all the possible subsets
		ll cs = 0;
		for(int j = 0; j < n; j++)
			if(i>>j & 1)
				cs += p[j];
		if(cs <= s/2)
			ans = max (cs, ans);
	}
	cout<< s - (ans/2);
}

// https://user-images.githubusercontent.com/42804008/84826229-44fc4380-b040-11ea-9f5d-17dd3348f3d3.jpg
