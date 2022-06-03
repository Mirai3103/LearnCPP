#include <iostream>
using namespace std;

int * randomArray(int n){
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 20;
    }
    return arr;
}

int main()
{
    srand(time(NULL));
    int length = 9;
    int *arr = randomArray(length);
    for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int max1 = arr[0];
    int max2 = -1;
    int max3 = -1;
    for(int i = 1; i < length; i++){
        if(arr[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] > max2){
            max3 = max2;
            max2 = arr[i];
        }
        else if(arr[i] > max3){
            max3 = arr[i];
        }
    }
    cout << max1 << " " << max2 << " " << max3 << endl;
    return 0;
}
