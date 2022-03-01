#include <stdio.h>
#include <iostream>

using namespace std ;

void printArray(int *arr, int n);
void RemoveIndex(int *&arr , int *n , int k );

int main()
{
    int n,k;
    cout << "Enter the length of the array: ";
    cin >> n;
    int *arr = new int[n];
    if ( arr == NULL )
    {
        cout << "Memory error!!!" ;
    }
    else
    {
        cout << "Enter a value for array: " << endl ;
        for ( int i=0 ; i<n ; i++ )
        {
            printf("arr[%d] = ",i);
            scanf("%d", &arr[i]);
        }
        cout << "The entered array is: " << endl;
        printArray(arr,n);
        cout << "\nEnter the value K u want to delete: ";
        cin >> k;
        RemoveIndex(arr,&n,k);
        printArray(arr,n);
    }
    delete[] arr;
    return 0;
}

void printArray(int *arr, int n)
{
    for ( int i=0 ; i<n ; i++ )
    {
        cout << arr[i] << "\t" ;
    }
}

void RemoveIndex(int *&arr , int *n , int k )
{
    int *b =  new int[(*n)-1];
    int j = 0;
    for (int i = 0; i < *n; i++)
    {
        if(i!=k){
            b[j++] = arr[i];
        }
    }
    
    
    *n = j;
    delete[] arr;
    arr = b;
}