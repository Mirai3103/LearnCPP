#include <iostream>
using namespace std;

void lietke(int *arr, int i, int n)
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
        arr[i] = 0;
        lietke(arr, i + 1, n);
        arr[i] = 1;
        lietke(arr, i + 1, n);
    }
}
int main()
{
    int n = 3;
    int *arr = new int[3];
    lietke(arr, 0, 3);
}