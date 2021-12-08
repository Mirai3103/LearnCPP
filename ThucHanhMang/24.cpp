#include <iostream>
#include <limits.h>
using namespace std;


void xuatmang(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]=%d;  ",i,arr[i]);
    }
    printf("\n");
    
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
    xuatmang(arr,n);
}

int Min(int arr[], int n){
    int min  = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>=0){
            if(min > arr[i]){
            min = arr[i];
        }
        }
    }
    return min == INT_MAX?-1:min;
    
}
int main()
{
    
    int n;
    int arr[100];
    nhapngaunhien(arr,n);
    cout << Min(arr,n);
    return 0;
}
