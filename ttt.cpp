#include <iostream>
#include <math.h>
using namespace std;
float x, x1, x2, denta;
int main()
{
    float a, b, c;
    cout << "nhap a,b,c: ";
    cin >> a;
    cin >> b;
    cin >> c;
    if (a == 0)
    // Giai phuong trinh bac nhat bx+c=0
    {
        if (b == 0)
        {
            if (c == 0)
                cout << "phuong trinh VSN\n"
                     << endl;
            else
                cout << "phuong trinh vo nghiem\n"
                     << endl;
        }
        else
        {
            x = (-c / b);
            cout << "phuong trinh co nghiem x=" << x << endl;
        }
    }
    else // Giai phuong trinh 2 an
    {
        denta = (b * b - 4 * (a * c));
        if (denta < 0)
        {
            cout << "phuong trinh vo nghiem\n"
                 << endl;
        }
        else if (denta == 0)
        {

            x = -b / (2 * a);
            cout << "phuong trinh co nghiem kep x=" << x << endl;
        }
        else
        {
            x1 = (-b + sqrt(denta)) / (2 * a);
            x2 = (-b - sqrt(denta)) / (2 * a);
            cout << "phuong trinh co 2 nghiem x1=" << x1 << " va nghiem x2=" << x2 << endl;
        }
    }
    return 0;
}