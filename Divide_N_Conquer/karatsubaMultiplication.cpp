#include <bits/stdc++.h>
#define int long long 
using namespace std;

/*

   Naive Algorithm
    a(m-digits) * b (n-digits) is 0(mn).
    Order of Growth: Quadratic.
 
   Divide N Conquer Approach
    Running Time: 0(n^(lg3)) OR 0(n^(1.585))
    1: aH*bH
    2: aL*bL
    3: (aH+aL)*(bH+bL) - 1: - 2:
    4: a*b == 1:*base^(no.of-digits) + 2: + 3:*base(no.of-digits/2)

 */



// Returns number of digits in 'a'.
int nDigits(int a) {
    int na = 0;
    while (a > 0) {
        a /= 10;
        na++;
    }
    return na;
}


// Computes x*y using divide and conquer. (RECURSIVE)
int karatsuba (int x, int y) {
    // Base-case
    if (x < 10 && y < 10) return x*y;

    // Count number of digits in both x and y
    int nX = nDigits(x), nY = nDigits(y);

    // Choose max number of digits as n and divide it by two take ceiling.
    int n =(int) ceil(max(nX, nY) / 2.0); 
    
    // This is the magnitude of power by which we will divide number with base==10
    int mul = (int)pow(10, n);

    // DIVIDE STEP
    int xH = x /mul, xL = x % mul;
    int yH = y / mul, yL = y % mul;
    
    // RECURSIVELY SOLVE SMALLER SUB-PROBLEMS : CONQUER STEP
    int a = karatsuba(xH,yH), b = karatsuba(xL,yL), c = karatsuba(xH+xL, yL+yH) - a - b;
    
    // COMBINE STEP
    return a*(int)pow(10,2*n) + b + c*(int)pow(10,n);
}


int32_t main () { 
    int n, a, b;
    cout<<"Insert two integers: ";
    cin>>a>>b;
    cout<<karatsuba(a, b)<<endl;
    return 0;
}