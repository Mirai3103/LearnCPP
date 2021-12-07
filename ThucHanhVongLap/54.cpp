#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n=-1,x;
    cout << " nhap x: ";
    cin  >> x;
    while (n<0)
    {
        cout << "nhap n: ";
        cin >>n;
    }
    
    int s =0;
    int p =1;
    int dau = 1;
    for (int i = 1; i <= n; i++)
    {
        dau = dau*-1;
        p = p* x*x;
        s = s+dau*p;
    }
    cout << s;
    return 0;
}
