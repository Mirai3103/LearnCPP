#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
void nhapngaunhien(int arr[], int &n){
    cout << "nhap so phan tu cua mang: ";
    cin >>n;
    srand (time(NULL)); 
    int y = 10;
    int ranNumber = rand()%y;
    for (int i = 0; i < n; i++)
    {
        arr[i] = ranNumber;
        
        ranNumber = rand()%y+ranNumber+1;
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
    int x,y;

    int arr[100];
    nhapngaunhien(arr,n);
    xuatmang(arr,n);
    return 0;
}
