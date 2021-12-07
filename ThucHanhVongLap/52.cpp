#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double s = 1;
    for (int i = 1; i <= n; i++)
    {
        s = 1.0 / (1 + s);
    }
    cout << s;
    return 0;
}
