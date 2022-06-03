#include <iostream>
#include <math.h>
#include <map>
using namespace std;

int cach2(int *arr, int n)
{
    map<int, bool> aMap;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        aMap[arr[i]] = true;
    }
    for (auto a : aMap)
    {
        cout << a.first << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 16, 16, 5, 16};
    int n = 6;
    cach2(arr, n);
    return 0;
}
