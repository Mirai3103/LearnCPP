// Câu 1: Đếm số lượng chữ số nguyên dương của số n. Ví dụ: 2357 => 4 chữ số
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
    int n;
    cin >> n;
    cout << demNguyenDuong(n);
    return 0;
}
