#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cin >> x >> n;
    double s = x;
    int tu = 1;
    int mau = 0;
    for (int i = 1; i <= n; i++)
    {
        tu = tu * x * x;
        mau = mau * (2 * i - 1) * 2 * i;
        s += 1.0 * tu / mau;
    }
    cout << "kq:" << s;
    return 0;
}
