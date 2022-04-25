#include <iostream>
using namespace std;

void lietkehoanvi(int *arr, int i, int *tap, int n)
{
    if (i == n)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[j];
        }
        cout << endl;
    }
    else
    {
        for (int k = 0; k < n; k++)
        {
            arr[i] = tap[k];
            lietkehoanvi(arr, i + 1, tap, n);
        }
    }
}
int main()
{

    int tap[] = {1, 2, 3};
    int n = 3;
    int *arr = new int[n];
    lietkehoanvi(arr, 0, tap, n);
}
