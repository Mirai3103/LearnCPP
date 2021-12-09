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
    int x = 10;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%x;
    }
    xuatmang(arr,n);
}

void solve(int arr[], int n, int x){
    for (int i = 0; i < n; i++)
    {
        for (int j =i+1; j < n; j++)
        {
            if(arr[i]+arr[j]==x){
                printf("a[%d] va a[%d] = (%d, %d)\n",i,j, arr[i], arr[j]);
            }
        }
        
    }
    
    
}
int main()
{
    
    int n,x;

    int arr[100];
    nhapngaunhien(arr,n);
    cout <<"nhap x: ";
    cin >>x;
    solve(arr,n,x);
    
    return 0;
}
