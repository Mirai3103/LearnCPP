#include <iostream>
#include <math.h>
using namespace std;


bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0) return false;
    }
    return n>=2;
}
int main()
{
    int n =10;
    int a = 2;
    for (int i = 1; i <= n; i++)
    {
        if(isPrime(a)){
            cout << a <<"; ";
        }
        a++;
    }
    
    return 0;
}
