#include <iostream>
using namespace std;

void lietketohop(int *arr, int i, int *tap, int n, int k)
{
    if (i == k)
    {
        for (int j = 0; j < k; j++)
        {
            cout << arr[j];
        }
        cout << endl;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (tap[j] != -1)
            {
                arr[i] = tap[j];
                int temp = tap[j];
                tap[j] = -1;
                lietketohop(arr, i + 1, tap, n, k);
                tap[j] = temp;
            };
        }
    }
}
int main()
{

    int tap[] = {1, 2, 3};
    int n = 3;
    int k = 2;
    int *arr = new int[2];
    lietketohop(arr, 0, tap, n, k);
}
