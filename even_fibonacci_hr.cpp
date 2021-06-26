int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        // fn = 4*f(n-1) + f(n-2);
        // f[1] = 2 & f[0] = 0;
        long f1 = 2, f0 = 0;
        long long sum = 0;
        while(f1 <= n)
        {
            sum += f1;
            long temp = f1;
            f1 = (4 * f1) + f0;
            f0 = temp;
        }
        cout << sum << endl;
    }
    return 0;
}
