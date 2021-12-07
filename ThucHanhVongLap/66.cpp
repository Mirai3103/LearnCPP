#include <iostream>
using namespace std;
void inTamGiac(int n)
{
    int max = n + n - 1;
    for (int i = 1; i <= n; i++)
    {
        int so_ngoi_sao = i + i - 1;
        for (int j = max; j >= 1; j--)
        {
            if (j <= so_ngoi_sao)
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
}
int main()
{
    int n;
    cout << "nhap chieu cao: ";
    cin >> n;
    inTamGiac(n);

    return 0;
}
