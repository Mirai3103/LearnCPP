#include <iostream>
#include <limits.h>
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
    int min1, min2;
    if (arr[0] >= arr[1])
    {
        min1 = arr[1];
        min2 = arr[0];
    }
    else
    {
        min1 = arr[0];
        min2 = arr[1];
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] < min1)
        {
            min2 = min1;
            min1 = arr[i];
        }
        else
        {
            if (arr[i] != min1)
            {
                if ((arr[i] < min2))
                {
                    min2 = arr[i];
                }
            }
        }
    }
    return min2;
}
int main()
{

    int n, x;

    int arr[100];
    nhapngaunhien(arr, n);
    cout << solve(arr, n);

    return 0;
}
