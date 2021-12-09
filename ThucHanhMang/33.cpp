#include <iostream>
#include <limits.h>
using namespace std;

void xuatmang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]=%d;  ", i, arr[i]);
    }
    printf("\n");
}
void nhapngaunhien(int arr[], int &n)
{
    cout << "nhap so phan tu cua mang: ";
    cin >> n;
    srand(time(NULL));
    int x = 100;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % x;
    }
    xuatmang(arr, n);
}
int UCLT2so(int a, int b)
{
    if (a == b)
        return a;
    while (a * b != 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    return a + b;
}
int BCNN2so(int a, int b){
    return (a*b)/UCLT2so(a,b);
}
int UClNOfArr(int arr[], int n)
{
    int UCLN = arr[1];
    for (int i = 1; i < n ; i++)
    {
        UCLN = UCLT2so(UCLN, arr[i]);
    }
    return UCLN;
}
int BCNNOfArr(int arr[], int n)
{
    int BCNN = arr[1];
    for (int i = 1; i < n ; i++)
    {
        BCNN = BCNN2so(BCNN, arr[i]);
    }
    return BCNN;
}
void nhapmang(int arr[], int &n)
{
    cout << "nhap so phan tu cua mang: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << (i + 1) << ": ";
        cin >> arr[i];
    }
}

int main()
{

    int n, k;

    int arr[100];
    nhapmang(arr, n);
    cout << "ucln: "<<UClNOfArr(arr,n) << endl;
    cout << "bcnn: "<<BCNNOfArr(arr,n) ;
    return 0;
}
