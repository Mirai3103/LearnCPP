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
void SelectionSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void solve(int arr[], int n)
{
    int tich;
    int index1 = 0, index2 =1,index3 =2;
    int tichmax = arr[0]*arr[1]*arr[2];
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                tich = arr[i]*arr[j]*arr[k];
                if(tich > tichmax){
                    tichmax = tich;
                    index1 = i;
                    index2 = j;
                    index3 = k;
                }
            }
        }
    }
    printf("(%d, %d, %d)", index1,index2,index3);
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
    nhapngaunhien(arr, n);
    solve(arr, n);

    return 0;
}
