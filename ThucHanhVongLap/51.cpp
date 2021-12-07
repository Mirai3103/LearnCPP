#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double s =0;
    for (int i = 0; i < n; i++)
    {
        s = sqrt(2+s);
    }
    cout << s;
    return 0;
}
