#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void xuatmang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "; ";
    }
}
void taongaunhien(int arr[], int &n)
{
    cout << "nhap so phan tu cua mang: ";
    cin >> n;
    srand(6969);
    int y = 50;
    int ranNumber = rand() % y;
    for (int i = 0; i < n; i++)
    {
        arr[i] = ranNumber;

        ranNumber = rand() % y;
    }
    xuatmang(arr, n);
}

void nhapMang(int arr[], int &n)
{
    cout << "nhap so phan tu cua mang: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap phan tu thu " << (i + 1);
        cin >> arr[i];
    }
}
double solve(int arr[], int n)
{

    int sum = 0;
    int i = 0;
    while (arr[i] >= 0 && i < n)
    {
        sum = sum + arr[i];
        i++;
    }

    return sum * 1.0 / i;
}
int main()
{

    int n;

    int arr[100];
    nhapMang(arr, n);

    cout << solve(arr, n);

    return 0;
}
