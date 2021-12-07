#include <iostream>
using namespace std;

int main()
{
    int n, donvi;
    cin >> n;

    int max = 0;
    while (n != 0)
    {
        donvi = n % 10;
        n = n / 10;
        if (max < donvi)
        {
            max = donvi;
        }
    }
    cout << "chu so lon nhat la " << max;
    return 0;
}
