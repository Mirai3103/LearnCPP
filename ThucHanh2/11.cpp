#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Nhap 3 so a, b ,c: \n";
    cin >> a >> b >> c;

    if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
    {
        if ((a == b) || (b == c) || (c == a))
        {
            cout << "day la tam giac vuong can\n";
        }
        else
        {
            cout << "khong phai la tam giac vuong can";
        }
    }

    else
    {
        cout << "khong phai la tam giac vuong can";
    }

    return 0;
}
