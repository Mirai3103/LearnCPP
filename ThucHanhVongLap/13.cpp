#include <iostream>
using namespace std;

int main()
{
    int n, donvi;
    int dem = 1;
    cin >> n;

    int max = 0;
    while (n != 0)
    {
        donvi = n % 10;
        n = n / 10;
        if (max < donvi)
        {
            max = donvi;
            dem = 1;
        }
        else
        {
            if (max == donvi)
            {
                dem++;
            }
        }
    }
    cout << "chu so lon nhat la " << max << " axuat hien " << dem << " lan";
    return 0;
}
