#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;
void xuatmang(int arr[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        printf("%3d; ", arr[i]);
    }
    cout << endl;
}
void nhapngaunhien(int arr[], int n)
{
    srand(2000);
    int x = 5000;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % x;
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
               swap(arr[j] , arr[i]);
            }
        }
    }
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

////////////////////////////////////////////////
void DeleteElement(int *heap, int n)
{
    swap(heap[0], heap[n - 1]);
    n -= 1;
    int parent = 0;
    int childLeft = parent * 2 + 1;
    int childRight = parent * 2 + 2;
    while (childRight < n)
    {
        if (heap[childLeft] > heap[childRight])
        {
            if (heap[parent] < heap[childLeft])
            {
                swap(heap[parent], heap[childLeft]);
                parent = childLeft;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (heap[parent] < heap[childRight])
            {
                swap(heap[parent], heap[childRight]);
                parent = childRight;
            }
            else
            {
                break;
            }
        }

        childLeft = parent * 2 + 1;
        childRight = parent * 2 + 2;
    }
}
void addToMaxHeap(int arr[], int x, int i)
{
    arr[i] = x;
    int parent;
    while (i != 0)
    {
        parent = (i - 1) / 2;
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
        }else{
            break;
        }
        i = (i - 1) / 2;
    }
}
void createMax_Heap(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        addToMaxHeap(arr, arr[i], i);
    }
}
void heapSort(int *arr, int n)
{
    createMax_Heap(arr, n);
    while (n > 1)
    {
        DeleteElement(arr, n);

        n--;
    }
}
int compare(const void* a, const void* b)
{
    const int* x = (int*) a;
    const int* y = (int*) b;
    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;
    return 0;
}
int main()
{
    int n;
    // cin >> n;
    n = 5000;
    int *arr = new int[n];
    nhapngaunhien(arr, n);

    auto start = high_resolution_clock::now();
    Qsort(arr,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    delete[] arr;
    return 0;
}
