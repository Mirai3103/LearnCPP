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
int solve(int arr[], int n, int k)
{
    SelectionSort(arr, n);
    return arr[k-1];
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
    cout << "nhap k: ";
    cin >> k;
    if(k <= 0 || k>n){
        cout <<"khong the tim!";
    }else{
        cout << "phan tu lon thu "<<k<< " la: " <<solve(arr, n, k);
    }
    
    

    return 0;
}
