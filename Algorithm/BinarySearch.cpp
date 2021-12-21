#include <iostream>
using namespace std;
void xuatmang(int arr[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        printf("%3d; ", arr[i]);
    }
}
void nhapngaunhien(int arr[], int n)
{
    srand(6969);
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
int BinarySearch(int arr[], int left, int right, int x){
    int mid = (left + right)/2;
    if(arr[mid] == x) return mid;
    if(left < right){
        if(arr[mid] < x){
            return BinarySearch(arr,mid+1, right,x);
        }else
        {
            return BinarySearch(arr, left, mid-1,x);
        }
    }
    return -1;
}
int Search(int arr[],int length, int x){
    if(arr[0]== x) return 0;
    if(arr[length-1]== x) return length-1;
    return BinarySearch(arr, 0,length-1,x);
}
int BinarySearchWithoutRecursion(int arr[], int length, int x){
    if(arr[0]== x) return 0;
    if(arr[length-1]== x) return length-1;
    int l = 0;
    int r = length-1;
    int mid;
    while (l <= r)
    {
        mid = (l+r)/2;
        if(arr[mid]==x) return mid;
        if(arr[mid] < x){
            l = mid +1;
        }else{
            r = mid -1;
        }
    }
    return -1;
    
}
int main()
{
    int arr[100] = {};
    int n;
    cin >> n;
    nhapngaunhien(arr, n);
    xuatmang(arr, n);
    QuickSort(arr,0,n);
    xuatmang(arr, n);
    int x;
    cout << endl;
    cin >> x;
    cout << BinarySearchWithoutRecursion(arr, n, x);
    return 0;
}
