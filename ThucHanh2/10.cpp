#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Nhap 3 so a, b ,c: \n";
    cin >> a >> b >> c;

    if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
    {
        cout << "day la tam giac vuong \n";
    }

    else
    {
        cout << "khong phai la tam giac vuong";
    }

    return 0;
}
