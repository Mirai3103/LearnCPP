#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, i=1;
    double sum = 0;
    cout << " Moi ban nhap gioi han:";
    cin >> n;
    while (i <= n && n > 0)
    {
        cout << "\n i=" << i;
        sum += 1.0/i;
        i++;
    }
    cout << "\n vay tong cua gioi han la:" << sum;
    return 0;
}