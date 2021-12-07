#include <iostream>
using namespace std;
void findSubArrEqualX(int arr[], int n, int x){
    int k,sum, lastindex;
    int isFinded= false;
    for (int i = 0; i < n; i++)
    {
        k = i;
        sum = arr[i];
        do{
            k++;
            sum+= arr[k];  
        } while(sum <=x && !isFinded);
        if(sum == x && !isFinded){
            lastindex = k;
            isFinded = true;
        }
        if(isFinded){
            cout << arr[i]<<" ";
            if(i == lastindex){
                break;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    findSubArrEqualX(arr, n, x);
    return 0;
}