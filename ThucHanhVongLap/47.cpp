#include <iostream>
using namespace std;
void scann(int &n)
{
    do
    {
        cout << "nhap n: ";
        cin >> n;
    } while (n < 0);
}
int main()
{
    int n;
    scann(n);
    int before = 0;
    double s = 0;
    for (int i = 1; i <= n; i++)
    {
        before += i;
        s += 1.0 / before;
    }
    cout << "\n"
         << s;
    return 0;
}
