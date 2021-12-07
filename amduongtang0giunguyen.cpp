#include <iostream>
using namespace std;
#include <stdio.h>
const int Max = 100;

void nhapmang(int a[][Max], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Nhap a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
}
void xuatmang(int a[][Max], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %2d", a[i][j]);
        }
        cout << "\n";
    }
}
void hoandoi(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void xuatmang1chieu(int arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        printf(" %2d", arr[i]);
    }
}
void sort(int arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < k; j++)
        {
            if (arr[i] * arr[j] > 0)
            {
                if (arr[i] > arr[j])
                {
                    hoandoi(arr[i], arr[j]);
                }
            }
        }
    }
}
void arr1to2chieu(int arr[],int k, int m, int n){
    int a[Max][Max];
    int z =0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j]=arr[z];
            z++;
        }
    }
    xuatmang(a,m,n);
    
}

void arr2sang1chieu(int a[][Max], int m, int n)
{
    int arr[m * n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[n * i + j] = a[i][j];
        }
    }

    sort(arr, m * n);
    arr1to2chieu(arr, m*n,m ,n);
}


int main()
{
    int a[Max][Max];
    int n, m;
    // do{
    //     cout<<"Nhap so hang, so cot: ";
    //     cin>>m>>n;
    // }while(n<0 || m<0 || n>Max || m>Max);
    n = 3;
    m = 3;
    a[0][0] = 5;
    a[0][1] = -2;
    a[0][2] = -1;
    a[1][0] = 3;
    a[1][1] = 0;
    a[1][2] = 7;
    a[2][0] = 4;
    a[2][1] = 2;
    a[2][2] = -6;

    // nhapmang(a,m,n);
    xuatmang(a,m,n);
    cout<<"==============\n";
    arr2sang1chieu(a, m, n);
}