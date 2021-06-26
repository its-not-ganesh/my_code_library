// Second Method for Two knights
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n;
	cin >> n;
	for(int k = 1; k < n; k++){
		ll a1 = k * k; // total positions
		ll a2 = a1 * (a1 - 1) / 2; // initial answer would be the total number of places we choose two
		if(k > 2)
			a2 -= 4 * (k-1) * (k-2); // removing the number of ways knights can attack each other
		cout << a2 <<"\n";
	}
	return 0; 
}
// this is a solution using complimentary counting, i.e. you remove the 
