#include <iostream>
using namespace std;
#include <math.h>
int UCLN(int a, int b)
{
    if (a % b == 0)
        return b;
    return UCLN(b, a % b);
}
int fibonacci(int n)
{
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
long dectoibin(int n){
    int i = 0;
    long bin = 0;
    while (n!=0)
    {
        
        bin =n%2*pow(10,i) + bin;
        i++;
        n = n /2;
    }
    return bin;
}
int main()
{

    cout << dectoibin(96);
}
