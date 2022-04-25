#include <iostream>
using namespace std;

int digitCount(int n)
{
    if (n == 0)
        return 0;
    return 1 + digitCount(n / 10);
}

int main()
{
    int n;
    do
    {
        cout << "nhap N nguyen duong ( >0): ";
        cin >> n;
    } while (n <= 0);
    cout << n << " co " << digitCount(n) << " chu so.";
    return 0;
}