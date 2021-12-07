#include <iostream>
using namespace std;
void inTamGiam(int n){
    int max = n + n - 1;
    for (int i = 1; i <= n; i++)
    {
        int so_ngoi_sao = 2*i  - 1;
        for (int j = 1; j <=max; j++)
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
    inTamGiam(n);

    return 0;
}