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
bool compare(int x, int y){
    return x > y; //max heap, x < y min heap
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
void heapify(int *arr, int n, int parent) // faster
{
    int childLeft;
    int childRight;
    int max;
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
           
            max = compare(arr[childLeft] ,arr[childRight]) ? childLeft : childRight;
        }
        
        if (compare(arr[max],arr[parent] ))
        {
            swap(arr[parent], arr[max]);
            heapify(arr,n,max);
        }
    }
}
void PopFirstAndPushback(int *heap, int n)
{
    swap(heap[0], heap[n - 1]); // delete firt e
    n -= 1;
    heapify(heap,n,0);
    
}
void addToHeap(int arr[], int x, int i) // cach 1 nlogn
{
    arr[i] = x;
    int parent;
    while (i != 0)
    {
        parent = (i - 1) / 2;
        if (compare(arr[i] , arr[parent]))
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
void create_Heap(int *arr, int n)//// cach 1 nlogn
{
    for (int i = 1; i < n; i++)
    {
        addToHeap(arr, arr[i], i);
    }
}
void createHeap(int *arr, int n){ // logn

    for (int i = (n-1)/2; i >=0; i--)
    {
        heapify(arr,n,i);  
    }
    
}
// void heapSort(int *arr, int n){
//     createHeap(arr,n);
    
//     for (int i = n; i >1; i--)
//     {
//         PopFirstAndPushback(arr,i);
//     }
// }
int main()
{
    int n;
    n = 5000;
    int *arr = new int[n];
    nhapngaunhien(arr,n);
    
    createHeap(arr,n);
    delete[] arr;
    return 0;
}
