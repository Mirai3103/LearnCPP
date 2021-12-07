#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double a, b, c;
    cout << "nhap 3 canh a,b,c: \n ";
    cin >> a, b, c;
    double P, S, hA, hB, hC;
    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        P = a + b + c;
        int nuachuvi = P / 2;
        S = sqrt(nuachuvi * (nuachuvi - a) * (nuachuvi - b) * (nuachuvi - c));
        hA = S / a;
        hB = S / b;
        hC = S / c;
    }
    else
    {
        cout << "khong phai tam giac";
    }
    
    return 0;
}
