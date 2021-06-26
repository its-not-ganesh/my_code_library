#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, xo;
        cin >> n;
        switch (n % 4) {
            case 0:
                cout << "1 " << n << "\n";
                break;
            
            case 1:
                cout << "1 " << 1 << "\n";
                break;

            case 2:
                cout << "2 " << n << " " << (n ^ n + 1) << "\n";
                break;

            default:
                cout << "0\n";
                break;
        }
    }
    return 0;
}
