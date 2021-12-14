#include <iostream>
using namespace std;
#include <stdlib.h> 
#include <time.h>
void xuatmang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "; ";
    }
    
}
void nhapmang(int arr[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap Phan tu thu " << (i + 1) << ":";
        cin >> arr[i];
    }
}
void nhapngaunhien(int arr[], int &n){
    cout << "nhap so phan tu cua mang: ";
    cin >>n;
    srand (time(NULL)); 
    int x = 50;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%x - rand()%x;
    }
    xuatmang(arr, n);
    cout << endl;
}
int solve(int arr[], int n)
{
    int min = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > 0){
           if(arr[i] < min) {
               min = arr[i];
               index = i;
           }
        }
    }
    return index;
    
}

int main()
{
    int arr[100];

    int n;
    nhapngaunhien(arr, n);
    cout <<solve(arr, n);
    return 0;
}
