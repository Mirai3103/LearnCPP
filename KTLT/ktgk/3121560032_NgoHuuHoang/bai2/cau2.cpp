#include <iostream>
using namespace std;

// su dung de qui
int Yn(int n);
int Xn(int n);
int Yn(int n)
{
    if (n == 0)
        return 1;
    return 3 * Xn(n - 1) + 2 * Yn(n - 1);
}
int Xn(int n)
{
    if (n == 0)
        return 1;
    return Xn(n - 1) + Yn(n - 1);
}

// khon su dung de qui
struct Fibonaci
{
    int x;
    int y;
};

Fibonaci getXY(int n)
{
    Fibonaci Fn;
    Fn.x = 1;
    Fn.y = 1;
    int i = 0;
    while (i < n)
    {
        int temp = Fn.x;
        Fn.x = Fn.x + Fn.y;
        Fn.y = 3 * temp + 2 * Fn.y;
        i++;
    }
    return Fn;
}
int main()
{
    // su dung de qui
    int n;
    do
    {
        cout << "nhap N >=0: ";
        cin >> n;
    } while (n < 0);
    printf("Su dung de qui: \n");
    printf("X%d = %d,   Y%d = %d\n", n, Xn(n), n, Yn(n));
    printf("Khong su dung de qui: \n");
    Fibonaci nonRecursive = getXY(n);
    printf("X%d = %d,   Y%d = %d\n", n, nonRecursive.x, n, nonRecursive.y);
}
