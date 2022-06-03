#include <iostream>
using namespace std;


int evenCounter(int *arr, int start, int end){
    if(start == end){
        if(arr[start] %2 ==0){
            return 1;
        }
        return 0;
    }
    return evenCounter(arr,start, (end+start)/2) + evenCounter (arr, (end+start)/2 +1, end);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7};
    cout << evenCounter(arr,0,6);
    return 0;
}
