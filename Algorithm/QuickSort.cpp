#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void InputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("nhap arr[%d]", i);
        scanf("%d", &arr[i]);
    }
}
void xuatmang(int arr[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        printf("%3d; ", arr[i]);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int split(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left;
    int j = right;
    while (i < j)
    {
        do
        {
            i++;
        } while (i < right && arr[i] < pivot);
        do
        {
            j--;
        } while (j > left && arr[j] > pivot);
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    if (left != j)
    {
        swap(arr[left], arr[j]);
    }

    return j;
}
void QuickSort(int arr[], int left, int right)
{

    if (left < right)
    {
        int splitPosition = split(arr, left, right);

        QuickSort(arr, left, splitPosition);
        QuickSort(arr, splitPosition + 1, right);
    }
}

void Qsort(int a[], int length)
{
    QuickSort(a, 0, length);
}
// void QsortWithoutRecursion(int a[],int length){
//     int start = 0;

// }
void nhapngaunhien(int arr[], int n)
{
    srand(time(NULL));
    int x = 50;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % x;
    }
    cout << "nhap ngau nhien";
    xuatmang(arr, n);
}
int main()
{
    int arr[100];
    int n;
    scanf("%d", &n);
    nhapngaunhien(arr, n);
    Qsort(arr, n);
    cout << endl;
    xuatmang(arr, n);
    return 0;
}
