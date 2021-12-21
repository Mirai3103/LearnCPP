#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void xuatmang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]=%d;  ", i, arr[i]);
    }
    printf("\n");
}
void nhapngaunhien(int arr[], int &n)
{
    cout << "nhap so phan tu cua mang: ";
    cin >> n;
    srand(time(NULL));
    int x = 100;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % x;
    }
    xuatmang(arr, n);
}

int solve(int arr[], int n)
{

    if (n == 1)
        return arr[0];
    int max2, max1;
    if (arr[0] >= arr[1])
    {
        max2 = arr[1];
        max1 = arr[0];
    }
    else
    {
        max2 = arr[0];
        max1 = arr[1];
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else
        {
            if (arr[i] != max1)
            {   
                if ((arr[i] > max2))
                {
                    max2 = arr[i];
                }
            }
        }
    }
    return max2;
}
int main()
{

    int n, x;

    int arr[100];
    nhapngaunhien(arr, n);
    cout << solve(arr, n);
    sort(arr,arr+n);

    return 0;
}
