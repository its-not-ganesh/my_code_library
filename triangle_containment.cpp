#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

   
double area(long x1, long y1, long x2, long y2, long x3, long y3)
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);

bool isInside(long x1, long y1, long x2, long y2, long x3, long y3, long x, long y)
{  
   double A = area (x1, y1, x2, y2, x3, y3);
 
   double A1 = area (x, y, x2, y2, x3, y3);
 
   double A2 = area (x1, y1, x, y, x3, y3);
 
   double A3 = area (x1, y1, x2, y2, x, y);
   
   return (A == A1 + A2 + A3);
}

int main() {
    long a,b,c,d,e,f,n;
    cin >> n;
    long sum = 0;
    while(n--){
        cin >> a >> b >> c >> d >> e >> f;
        if(isInside(a,b,c,d,e,f,0,0))
            sum += 1;
    }
    cout << sum << endl;
    return 0;
}
