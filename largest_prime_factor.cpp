int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long maxPrime = 1;
        while(n % 2 == 0)
        {
            n /= 2;
            maxPrime = 2;
        }
        for(long i = 3; i <= sqrt(n); i += 2)
        {
            while(n % i == 0)
            {
                n /= i;
                maxPrime = i;
            }
        }
        if(n > 2)
            maxPrime = n;
        cout << maxPrime << endl;
    }
    return 0;
}
