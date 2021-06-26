int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        n = n-1;
        long long int n3 = n / 3;
        long long int n5 = n / 5;
        long long int n15 = n / 15;
        long long int sum3 = 0, sum5 = 0, sum15 = 0;
        sum3 = (n3 * (6 + (n3-1) * 3)) / 2;
        sum5 = (n5 * (10 + (n5-1) * 5)) / 2;
        sum15 = (n15 * (30 + (n15-1) * 15)) / 2;
        // cout << n3 << " " << n5 << " " << sum15 << endl;
        cout << (sum3 + sum5 - sum15) << endl;        
    }
    return 0;
}
