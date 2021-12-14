#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
void tofiboArr(int arr[], int &n){
    cout << "nhap n: ";
    cin >>n;
    arr[0] = 1;
    arr[1]= 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i-1]+arr[i-2];
    }
}
void xuatmang(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<"; ";
    }
}
int main()
{
    
    int n;
    int arr[100];
    tofiboArr(arr,n);
    xuatmang(arr,n);
    return 0;
}
