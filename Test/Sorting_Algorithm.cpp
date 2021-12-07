#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a; 
    a = b;
    b = temp;
}
bool compare(int a, int b) { 
   return a>b;
}
void SelectionSort(int arr[], int length){ // sắp xếp chọn
    for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length-1; j++)
        {
            if (compare(arr[i], arr[j]))
            {
                swap(arr[i], arr[j]);
            }
            
        }
        
    }
    
}
int main()
{
    int arr[] = {3,2,8,4,10,45,33,23,14,67,45,89,24,43,99};
    int n = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<", ";
    }
    
    return 0;
}
