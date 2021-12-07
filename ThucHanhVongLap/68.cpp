#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "nhap chieu cao: ";
    cin >> n;
    int max = n + n - 1;
    for (int i = n; i >=1; i--)
    {
        int so_ngoi_sao_dong_nay = i + i - 1;
        for (int j = max; j >= 1; j--)
        {
            if (j <= so_ngoi_sao_dong_nay)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
