#include <iostream>

using namespace std;
int BinanySearch(int arr[], int n, int x)
{
    if (arr[0] == x)
        return 0;
    if (arr[n - 1] == x)
        return n - 1;
    int left = 0, right = n - 1;
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return arr[left] == x ? left : -1;
}
int LinearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
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
    cout << BinanySearch(arr, n, x);
    return 0;
}