#include <iostream>
using namespace std;

int demNguyenDuong(int n) // > 0
{
    if (n == 0)
        return 0;
    if (n % 10 > 0)
        return 1 + demNguyenDuong(n / 10);
    return 0 + demNguyenDuong(n / 10);
}

int main()
{
    cout << demNguyenDuong(2397);
    return 0;
}
