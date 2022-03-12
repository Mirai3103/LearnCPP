#include <iostream>
using namespace std;

// void merge(int *arr, int l, int mid, int r)
// {
//     for (size_t i = 0; i < count; i++)
//     {
//         /* code */
//     }
// }
int *merge(int *A, int *B, int lengthA, int lengthB)
{
    int i = 0, j = 0;
    int k = 0;
    int *C = new int[lengthA + lengthB];
    while (i < lengthA && j < lengthB)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    for (; j < lengthB; j++)
    {
        C[k++] = B[j++];
    }
    for (; i < lengthB; i++)
    {
        C[k++] = A[i++];
    }
    return C;
}
int *merge(int *arr, int l, int mid, int r)
{
    int i = 0, j = mid;
    int k = 0;
    int *C = new int[r - l + 1];
    while (i < mid && j <= r)
    {
        if (arr[i] < arr[j])
        {
            C[k++] = arr[i++];
        }
        else
        {
            C[k++] = arr[j++];
        }
    }
    for (; j <= r; j++)
    {
        C[k++] = arr[j++];
    }
    for (; i < mid; i++)
    {
        C[k++] = arr[i++];
    }
    return C;
}
void mergeSort(int *A, int length)
{
    int me = 1;
    while (me > length)
    {
        for (int i = 0; i < length; i = i + me)
        {
            /* code */
        }
    }
}
int main()
{
    int A[] = {1, 5, 8, 12, 16};
    int B[] = {-1, 2, 4, 6, 9, 10, 13, 15, 16, 19};
    int arr[] = {1, 5, 8, 12, 16, -1, 2, 4, 6, 9, 10, 13, 15, 16, 19};
    int lengthA = 5;
    int lengthB = 10;
    int *C = merge(arr, 0, 5, 14);
    for (int i = 0; i < 15; i++)
    {
        cout << C[i] << ", ";
    }
    cout << endl;

    return 0;
}
