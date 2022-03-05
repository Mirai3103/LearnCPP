#include <iostream>
#include <stdio.h>

using namespace std;

void printArray( int *a , int n );
void cArray( int *a, int *b , int *c , int n , int m , int &p);

int main()
{
    int n,m,p;
    int *a = new int[n] ;
    int *b = new int[m] ;
    int *c = new int[p];
    if ( a == NULL || b == NULL || c == NULL )
    {
        cout << "Memory error!!!";
    }
    else
    {
        cout << "Enter the length of the array A: ";
        cin >> n ;
        cout << "Enter a value for array A: " << endl;
        for ( int i=0 ; i<n ; i++ )
        {
            printf("A[%d] = ",i);
            scanf("%d",&a[i]);
        }
        cout << "The entered array is: " << endl;
        printArray(a,n);
        cout << "\nEnter the length of the array B: ";
        cin >> m ;
        cout << "Enter a value for array B: " << endl;
        for ( int i=0 ; i<m ; i++ )
        {
            printf("B[%d] = ",i);
            scanf("%d",&b[i]);
        }
        cout << "The entered array is: " << endl;
        printArray(b,m);
        cout << "\nAfter merging array A and array B: " << endl;
        cArray(a,b,c,n,m,p);
        printArray(c,p);
    }
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}

void printArray( int *a , int n )
{
    for ( int i=0 ; i<n ; i++ )
    {
        cout << a[i] << "\t" ;
    }
}

void cArray( int *a, int *b , int *c , int n , int m , int &p)
{
    p = m + n;
    for ( int i=0 ; i<p ; i++ )
    {
        if (i<n)
        {
            c[i] = a[i];
        }
        else
        {
            c[i] = b[i-n];
        }
    }
}
