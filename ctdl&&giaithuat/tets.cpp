#include <iostream>
#include <stdio.h>

using namespace std;

void shakerSort(int *arr, int n);

int main(int argc, char const *argv[])
{
    int n;
    cout << "Nhap do lon cua mang: ";
    cin >> n;
    int *arr = new int[n];
    if (arr == NULL)
    {
        cout << "Loi vung nho";
    }
    else
    {
        cout << "Nhap gia tri cua mang" << endl;
        for (int i = 0; i < n; i++)
        {
            printf("arr[%d] = ", i);
            scanf("%d", &arr[i]);
        }
        cout << "Mang da nhap la: " << endl;
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
    cout << "\nMang sau khi sap xep: " << endl;
    shakerSort(arr, n);
    delete[] arr;
    return 0;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void shakerSort(int *arr, int n)
{
    int temp;
    int up = 0, down = n - 1, hv = 0;
    while (up < down)
    {
        for (int i = up; i <= down - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i] , arr[i + 1]);
                hv = i;
            }
        }
        down = hv;
        for (int i = down; i >= up + 1; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                hv = i;
            }
        }
        up = hv;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}