#include <iostream>
using namespace std;
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void insertionSort(int *arr, int n)
{
    int j;
    for (int i = 1; i < n - 1; i++)
    {
        j = i + 1;
        int pos = arr[j]; // 9
        for (; j >= 0 && arr[j - 1] > pos; j--)
        {
            if (arr[j - 1] > pos)
            {
                arr[j] = arr[j - 1];
                for (int i = 0; i < 12; i++)
                {
                    cout << arr[i] << ", ";
                }
            }
        }
        arr[j] = pos;
    }
}
int main()
{
    int arr[] = {7, 18, 9, 12, 3, 4, 1, 10, 8, 2, 5, 6};
    for (int i = 0; i < 12; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
    int n = sizeof(arr) / sizeof(int);
    insertionSort(arr, n);
    for (int i = 0; i < 12; i++)
    {
        cout << arr[i] << ", ";
    }
    return 0;
}
