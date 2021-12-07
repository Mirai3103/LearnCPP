#include <iostream>
using namespace std;// namespace name

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    cout << "nhap a, b , c, d: \n";
    cin >> a >> b >> c >> d;
    int max = a;
    // tim max 4 so
    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else
    {
        max = c;
    }
    if(max < d){
        max = d;
    }
    cout << max;
    return 0;
}
