#include <iostream>
using namespace std;
// s = x + x^3 + x^5 +...+x^(2n+1)
int Xn(int x, int n)
{
    if (n == 0)
        return x;
    return x * x * Xn(x, n - 1);
}
long S(int x, int n)
{
    if (n < 0)
        return 0;
    return Xn(x, n) + S(x, n - 1);
}

int main()
{
    int x, n;
    cout << "Nhap x: ";
    cin >> x;
    do
    {
        cout << "Nhap n: ";
        cin >> n;
    } while (n < 0);

    cout << S(x, n);
}