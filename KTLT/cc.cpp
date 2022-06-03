#include <iostream>
using namespace std;

int main()
{

    int arr[] = {2, 8, 11, 3, 5, 9, 10, 4, 17, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *F = new int[n];
    F[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int max = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j] && F[j] > max)
                max = F[j];
        }
        F[i] = max + 1;
    }
    for (int i = 0; i < n; i++)
        cout << F[i] << " ";
}
