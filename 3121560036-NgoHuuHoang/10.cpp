#include <iostream>
using namespace std;
#include <math.h>
int Factorial(int n)
{
    if (n == 0)
        return 1;
    return n * Factorial(n - 1);
}
double S(int x, int n ){
    if(n==1) return x;
    return pow(x, n)/Factorial(n)+S(x, n-1);
}


int main()
{
 
}