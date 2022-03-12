#include <iostream>
using namespace std;
int arr[100];
void inChuoiNhiPhan(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
void timChuoiNhiPhan(int n, int index = 0)
{
    if (index == 3)
    {
        inChuoiNhiPhan(n);
    }
    else
    {
        for (int i = 0; i <= 1; i++)
        {
            arr[index] = i;
            timChuoiNhiPhan(n, index + 1);
        }
    }
}

int main()
{
    timChuoiNhiPhan(3);
    return 0;
}
