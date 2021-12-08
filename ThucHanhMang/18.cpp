#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void NhapMangNgauNhien(int *arr, int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i]= rand()%100;
    }
    
}
int TongChuSo(int n){
    int dv = n%10;
    n = n /10;
    return n==0?dv:(dv+TongChuSo(n));
}
int TongCacChuSoCuaMang(int *arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum +=TongChuSo(arr[i]);
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    NhapMangNgauNhien(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    cout << endl << "tong ca chu so: "<< TongCacChuSoCuaMang(arr, n);
    


    delete[] arr;
    return 0;
}
