#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

void xuatmang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "; ";
    }
    
}
void taomangngaunhien(int arr[], int &n){ // co am co duong
    cout << "nhap so phan tu cua mang: ";
    cin >>n;
    srand (time(NULL)); 
    int x = 20;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%x - rand()%x;
    }
    xuatmang(arr, n);
    cout << endl;
}

void nhapmang(int arr[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap Phan tu thu " << (i + 1) << ":";
        cin >> arr[i];
    }
}
void solve(int arr[], int n, int tanso[], int &k)
{
    bool isCheck[100] = {};
    int dem;
    k = 0;
    for (int i = 0; i < n; i++)
    {
        if (!isCheck[i])
        {
            dem = 1;
            for (int j = i + 1; j < n ; j++)
            {
                if (arr[i] == arr[j])
                {
                    dem++;
                    isCheck[j] = true;
                }
            }
            tanso[k] = arr[i];
            k++;
            tanso[k] = dem;
            k++;
            // printf("%d xuat hien %d lan \n", arr[i], dem);
        }
        
    }
}

int main()
{
    int arr[100];
    int tanso[100];
    int n;
    int k;
    taomangngaunhien(arr, n);
    // nhapmang(arr,n); tu nhap mang
    solve(arr, n,tanso, k);
    for (int i = 0; i < k; i=i+2)
    {
        printf("phan tu %d xuat hien %d lan \n", tanso[i], tanso[i+1]);
    }
    
    return 0;
}
