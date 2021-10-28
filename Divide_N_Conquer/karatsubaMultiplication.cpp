#include <bits/stdc++.h>
#define int long long 
using namespace std;

/* Naive Algorithm
    a(m-digits) * b (n-digits) is 0(mn).
    Order of Growth: Quadratic.
 
   Divide N Conquer Approach
    Running Time: 0(n^(lg3)) OR 0(n^(1.585))
    1: aH*bH
    2: aL*bL
    3: (aH+aL)*(bH+bL) - 1: - 2:
    4: a*b == 1:*base^(no.of-digits) + 2: + 3:*base(no.of-digits/2)

 */

// We consider only desimal numbers. which gives us: 10 as base.
// A and B are two n-digit integers
int nDigits(int a) {
    int na = 0;
    while (a > 0) {
        a /= 10;
        na++;
    }
    return na;
}

int karatsuba (int x, int y) {
    // divide into lower and higher order bits
    if (x < 10 && y < 10) return x*y;
    int nX = nDigits(x), nY = nDigits(y);
    int n =(int) ceil(max(nX, nY) / 2.0); 
    int mul = (int)pow(10, n);
    int xH = x /mul, xL = x % mul;
    int yH = y / mul, yL = y % mul;
    int a = karatsuba(xH,yH), b = karatsuba(xL,yL), c = karatsuba(xH+xL, yL+yH) - a - b;
    return a*(int)pow(10,2*n) + b + c*(int)pow(10,n);
}

int32_t main () { 
    int n, a, b;
    cout<<"Insert n: "; cin>>n;
    cout<<"Insert two "<<n<<"-digit integers: ";
    cin>>a>>b;
    cout<<karatsuba(a, b)<<endl;
    return 0;
}