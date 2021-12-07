#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    cout << "nhap chieu cao: ";
    cin >> n;
    int max = n + n - 1;
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        int so_ngoi_sao = i + i - 1;
        for (int j = 1; j <=max; j++)
        {
            if (j <= so_ngoi_sao)
            {
                k++;
                printf("%3d",k);
            }
            else
            {
                printf("   ");
            }
        }
        cout << endl;
    }
    return 0;
}