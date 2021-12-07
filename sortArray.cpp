

#include <stdio.h>

void swap(int &a, int &b)
{
    int temp = a; 
    a = b;
    b = temp;
}
bool compare(int a, int b) { 
   return a<b;
}
void SelectionSort(int arr[], int length){ // sắp xếp chọn
    for (int i = 0; i < length-1; i++)
    {
        for (int j = i+1; j < length; j++)
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
    int arr[] = {3,2,8,4,10,45,33,23,14,99,67,45,89,24,43};
    int n = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr, n);
    int k = 2;
    for (int i = 0; i < n; ++i)
    {
        printf("%d; ", arr[i]);
    }
    printf("\nphan tu lon thu k %d", arr[k-1]);
    
    return 0;
}