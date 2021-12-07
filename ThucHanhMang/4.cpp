#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
void nhapngaunhien(int *arr, int n, int start, int end){
    srand (time(NULL)); 
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%(end-start)+start;
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
    cout << "nhap so phan tu cua mang: ";
    cin >>n;
    int x,y;
    cout << "nhap x,y: ";
    cin >>x>>y;
    int arr[100];
    nhapngaunhien(arr,n,x,y);
    xuatmang(arr,n);
    return 0;
}
