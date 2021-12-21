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
    int x = 50;
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
void LookDownAndSwap(int *heap, int n, int parent){
    int childLeft = parent * 2 + 1;
    int childRight = parent * 2 + 2;
    int max;
    while (childLeft < n)
    {
        if (childRight == n)
        {
            max = childLeft;
        }
        else
        {
            max = heap[childLeft] > heap[childRight] ? childLeft : childRight;
        }

        if (heap[parent] < heap[max])
        {
            swap(heap[parent], heap[max]);

            parent = max;
            childLeft = parent * 2 + 1;
            childRight = parent * 2 + 2;
        }
        else
        {
            break;
        }
    }
}
void DeleteElement(int *heap, int n) // xem laij
{
    swap(heap[0], heap[n - 1]);// delete firt e
    n -= 1;
    // int parent = 0;
    // int childLeft = parent * 2 + 1;
    // int childRight = parent * 2 + 2;
    // int max;
    LookDownAndSwap(heap,n, 0);
    // while (childLeft < n)
    // {
    //     if (childRight == n)
    //     {
    //         max = childLeft;
    //     }
    //     else
    //     {
    //         max = heap[childLeft] > heap[childRight] ? childLeft : childRight;
    //     }

    //     if (heap[parent] < heap[max])
    //     {
    //         swap(heap[parent], heap[max]);

    //         parent = max;
    //         childLeft = parent * 2 + 1;
    //         childRight = parent * 2 + 2;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
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
        }
        else
        {
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
void heapify(int *arr, int n) // faster
{
    int parent;
    int childLeft;
    int childRight;
    int max;
    for (int i = n - 1; i >= 0; i--)
    {
        parent = i;
        childLeft = parent * 2 + 1;
        childRight = parent * 2 + 2;

        if (childLeft < n)
        {
            if (childRight == n)
            {
                max = childLeft;
            }
            else
            {
                max = arr[childLeft] > arr[childRight] ? childLeft : childRight;
            }

            if (arr[parent] < arr[max])
            {
                swap(arr[parent], arr[max]);
                LookDownAndSwap(arr,n,max);
                // parent = max;
                // childLeft = parent * 2 + 1;
                // childRight = parent * 2 + 2;
                // while (childLeft < n)
                // {
                //     if (childRight == n)
                //     {
                //         max = childLeft;
                //     }
                //     else
                //     {
                //         max = arr[childLeft] > arr[childRight] ? childLeft : childRight;
                //     }

                //     if (arr[parent] < arr[max])
                //     {
                //         swap(arr[parent], arr[max]);

                //         parent = max;
                //         childLeft = parent * 2 + 1;
                //         childRight = parent * 2 + 2;
                //     }
                //     else
                //     {
                //         break;
                //     }
                // }
            }
        }
    }
}

void heapSort(int *arr, int n)
{
    heapify(arr, n);
    while (n > 1)
    {
        DeleteElement(arr, n);

        n--;
    }
}
int main()
{
    int n;
    // cin >> n;
    n = 7;
    int *arr = new int[n];
    arr[0] =10;
    arr[1] =20;
    arr[2] =15;
    arr[3] =12;
    arr[4] =40;
    arr[5] =25;
    arr[6] =18;
    createMax_Heap(arr,n);
    xuatmang(arr,n);

    
    

    

    delete[] arr;
    return 0;
}
