#include <iostream>
using namespace std;
void xuatmang(int arr[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        printf("%3d; ", arr[i]);
    }
    cout << endl;
}

void nhapngaunhien(int arr[], int n)
{
    srand(2000);
    int x = 50;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % x;
    }
}
bool compare(int x, int y){
    return x > y;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void merge(int *arr,int l,int m,int r){
    int lenght1 = m - l + 1;
    int lenght2 = r - m;
    int *temp1 =  new int[lenght1];
    int *temp2 =  new int[lenght2];
    for (int i = 0; i < lenght1; i++)
    {
        temp1[i] = arr[i+l];
    }
    for (int i = 0; i < lenght1; i++)
    {
        temp2[i] = arr[i+m+1];
    }

    int i =  0; int j = 0;int k = l;
    while (i < lenght1 && j < lenght2)
    {
        if(temp1[i]<temp2[j]){
            arr[k++] = temp1[i++];
        }else{
            arr[k++] = temp2[j++]; 
        }
    }
    for ( i ; i < lenght1; i++)
    {
        arr[k++] = temp1[i];
    }
    for ( j ; j < lenght2; j++)
    {
        arr[k++] = temp2[j];
    }
    delete [] temp1;
    delete [] temp2;
    
}
void mergesort(int *a, int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        xuatmang(a,10);
        merge(a,l,mid,r);
    }
}
void sort(int *arr,int length){
    mergesort(arr,0,length-1);
}
int main()
{
    int n;
    n = 10;
    int arr[10] = {8,2,0,1,6,5,9,3,4,-1};
    sort(arr,10);
    xuatmang(arr,10);
 
    return 0;
}
