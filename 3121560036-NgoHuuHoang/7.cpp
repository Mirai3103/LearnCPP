#include <iostream>
using namespace std;

double pow(double x, double y)
{
    if (y == 0)
        return 1;
    return x * pow(x, y - 1);
}

int main()
{
    double x, y;
    cin >> x >> y;
    cout << pow(x, y);
}