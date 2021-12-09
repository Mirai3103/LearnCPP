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

void solve(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]*1.0/3 == arr[i]){
                printf("(%d, %d); ",arr[i], arr[j]);
            }
        }
        
    }
    
}
void nhapmang(int arr[], int &n)
{
    cout << "nhap so phan tu cua mang: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu "<<(i+1)<<": ";
        cin >> arr[i];
    }
}


int main()
{

    int n;

    int arr[100];
    nhapmang(arr, n);
    solve(arr, n);

    return 0;
}
