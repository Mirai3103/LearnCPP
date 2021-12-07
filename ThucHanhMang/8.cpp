#include <iostream>

using namespace std;
bool timphantu(int arr[], int i, int a)
{
    for (int j = 0; j < i; j++)
    {
        if (arr[j] == a)
        {
            return true;
        }
    }
    return false;
}
void nhap(int arr[], int &n)
{
    cout << "nhap so phan tu cua mang: ";
    cin >> n;

    int a;

    for (int i = 0; i < n; i++)
    {
        bool khongtontai;
        do
        {
            cout << "nhap phan tu tu " << i + 1 << ": ";
            cin >> a;
            khongtontai = !(timphantu(arr, i, a));
            if (khongtontai)
            {
                arr[i] = a;
            }

        } while (!khongtontai);
    }
}
void xuatmang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "; ";
    }
}
int main()
{

    int n;
    int x, y;

    int arr[100];
    nhap(arr, n);
    xuatmang(arr, n);
    return 0;
}
