#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n){
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0) return false;
    }
    return n>=2;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout<<isPrime(n);
    return 0;
}
