#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp =a;
    a = b;
    b = temp;
}
int sort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if((arr[i] %2!=0 &&arr[j] %2==0)||(arr[i]>= arr[j])){
                swap(arr[i], arr[j]);
            }
            
        }
        
    }
    
}

void xuatmang(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\na[%d]= %d", i, a[i]);
    }
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    sort(arr,n);
    xuatmang(arr,n);
    return 0;
}
