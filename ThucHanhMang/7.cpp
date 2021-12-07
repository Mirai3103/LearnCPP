#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
void nhapngaunhien(int arr[], int &n){
    cout << "nhap so phan tu cua mang: ";
    cin >>n;
    srand (time(NULL)); 
    int x = 50;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%x - rand()%x;
    }
}
void xuatmang(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<"; ";
    }
}
void taomangBvaC(int arrA[],int arrB[],int arrC[],int nA, int &nB,int &nC){
    for (int i = 0; i < nA; i++)
    {
       if(arrA[i]>=0){
           arrB[nB] = arrA[i] ;
           nB++;
       }else{
           arrC[nC]= arrA[i];
           nC++;
       }
    }
}

int main()
{
    

    int arrA[100];
    int arrB[100];
    int arrC[100];
    int nA, nB=0,nC=0;
    nhapngaunhien(arrA,nA);
    taomangBvaC(arrA,arrB,arrC,nA,nB,nC);
    cout << "\nxuat mang a\n";
    xuatmang(arrA,nA);
    cout << "\nxuat mang b\n";
    xuatmang(arrB,nB);
    cout << "\nxuat mang c\n";
    xuatmang(arrC,nC);

    return 0;
}
