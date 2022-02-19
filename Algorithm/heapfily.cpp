#include <iostream>
using namespace std;
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
bool compare(int x, int y){
    return x > y; //max heap, x < y min heap
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void lookDown(int *arr, int length, int index){
    if(index*2+1 >= length) return;
   
    int willCompareindex = index*2+1;
    if(index*2+2<length){
        if(compare(arr[index*2+2],arr[willCompareindex])){
            willCompareindex++;
        }
    }
    if(compare(arr[willCompareindex],arr[index])){
        swap(arr[index], arr[willCompareindex]);
        lookDown(arr,length,willCompareindex);
    }
     

}

void heapify(int *arr, int length){
    for (int i = length-1; i >=0; i--)
    {
        lookDown(arr,length,i);
    }
    
}
void PopFirstAndPushBack(int *arr, int &length){
    length--;
    swap(arr[0], arr[length]);
    lookDown(arr,length,0);
    
}
int main()
{
    int n;
    n = 10;
    int *arr = new int[n];
    nhapngaunhien(arr,n);
     xuatmang(arr,n);
    heapify(arr,n);
     xuatmang(arr,n);
     for (int i = 0; i < 9; i++)
     {
         PopFirstAndPushBack(arr,n);
     }
     xuatmang(arr,10);
    delete[] arr;
    return 0;
}
