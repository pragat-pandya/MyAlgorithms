#include <iostream>
#include <string>
#define int long long
using namespace std;


// Recursive Binary Exponentiation;
int BiExpo (int base, int n) {

    // BASE-CASE
    if (n == 0) return 1;
    
    // FOR EVEN POWER
    if (n%2 == 0) return BiExpo(base*base, n/2);

    // FOR ODD POWER    
    else return BiExpo(base*base, n/2) * base;

}


// Iterative Divide and Conquer implementation.
int itrExpo (int base, int n) {
    
    // Running multiplication store
    int ans = 1; 

    // Loop while n > 0
    while (n) {

        // If n odd: Multiply answer with current value of base
        if (n & 1) ans *= base;
        
        // Divide n by 2
        n = n >> 1;

        // base becomes base*base 
        base *= base;

    }

    return ans;

}



int32_t main () {
    int base, ex; 

    cout<<"Enter Base: "; cin>>base; 
    cout<<"Enter Exponent: "; cin>>ex;

    cout<<to_string(base)+"^"+to_string(ex)+" = "<<itrExpo(base, ex)<<endl;

    return 0;
}