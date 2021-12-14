#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
void xuatmang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "; ";
    }
}
void nhapngaunhien(int arr[], int &n)
{
    cout << "nhap so phan tu cua mang: ";
    cin >> n;
    srand(time(NULL));
    int y = 10;
    int ranNumber = rand() % y;
    for (int i = 0; i < n; i++)
    {
        arr[i] = ranNumber;

        ranNumber = rand() % y + ranNumber + 1;
    }
    xuatmang(arr, n);
}
void nhapMang(int arr[], int &n)
{
    cout << "nhap so phan tu cua mang: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap phan tu thu " << (i) <<": ";
        cin >> arr[i];
    }
}

bool CoPhaiSoChinhPhuong(int n)
{
    int can = sqrt(n);
    return can*can == n;
}
void bai12(int arr[], int n)
{
    for (int i = 1; i < n; i = i + 2)
    {
        if (CoPhaiSoChinhPhuong(arr[i]))
        {
            cout << arr[i] << "; ";
        }
    }
}
int main()
{

    int n;

    int arr[100];
    nhapMang(arr, n);
    bai12(arr, n);
    return 0;
}
