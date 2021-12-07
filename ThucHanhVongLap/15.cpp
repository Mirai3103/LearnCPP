#include <iostream>
using namespace std;
// int UCLN(int a, int b)
// {
//     for (int i = a > b ? b : a; i >= 1; i--)
//     {
//         if (a % i == 0 && b % i == 0)
//         {
//             return i;
//         }
//     }
//     return 1;
// }
int UCLN(int a, int b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return a!=0?a:b;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << "UCLN: " << UCLN(a, b);

    return 0;
}
