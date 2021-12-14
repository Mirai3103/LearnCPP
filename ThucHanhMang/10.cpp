#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
void taongaunhien(int arr[], int &n){
    cout << "nhap so phan tu cua mang: ";
    cin >>n;
    srand (6969); 
    int y =50 ;
    int ranNumber = rand()%y;
    for (int i = 0; i < n; i++)
    {
        arr[i] = ranNumber;
        
        ranNumber = rand()%y;
    }
}
void xuatmang(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<"; ";
    }
}
void nhapMang(int arr[], int &n){
    cout << "nhap so phan tu cua mang: ";
    cin >>n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap phan tu thu "<<(i+1);
        cin >> arr[i];
    }
}
void solve(int arr[], int n, int x){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]+arr[j]==x){
                printf("(%d, %d) ; ",arr[i], arr[j] );
            }
        }
        
    }
    
}
int main()
{
    
    int n;
    

    int arr[100];
    taongaunhien(arr,n);
    xuatmang(arr,n);
    int x;
    cin >> x;
    solve(arr,n,x);

    return 0;
}
