#include <iostream>
using namespace std;
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// void insert(int *arr, int length, int element){
//     for (int i = length-1; i >=0; i++)
//     {

//     }

// }
void InsertionSort(int *arr, int length)
{
    for (int i = 1; i < length; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void BubbleSort(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = length - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                Swap(arr[j], arr[j - 1]);
            }
        }
    }
}

void SelectionSort(int *arr, int length)
{
    int min;
    for (int i = 0; i < length-1; i++)
    {
        int minKey = i;
        for (int j = i; j < length; j++)
        {
            if (arr[j] < arr[minKey])
            {
                minKey = j;
            }
        }
        Swap(arr[i], arr[minKey]);
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
    int n = sizeof(arr)/sizeof(int);
    SelectionSort(arr, n);
    for (int i = 0; i < 12; i++)
    {
        cout << arr[i] << ", ";
    }
    return 0;
}
