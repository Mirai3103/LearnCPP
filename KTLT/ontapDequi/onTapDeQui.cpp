#include <iostream>
#include <math.h>
#include <map>
using namespace std;

int sumOfArray(int *arr, int n)
{
    if (n <= 0)
        return 0;
    return arr[n - 1] + sumOfArray(arr, n - 1);
}

int maxOfArray(int *arr, int n)
{
    if (n == 1)
        return arr[0];
    return max(arr[n - 1], maxOfArray(arr, n - 1));
}
void printReverseArray(int *arr, int n)
{
    if (n == 0)
        return;
    cout << arr[n - 1] << "   ";
    printReverseArray(arr, n - 1);
}
int unDuplicateCountSolution1(int *arr, int n)
{

    bool flag = false;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            count++;
        }
        flag = false;
    }
    return count;
}
//
int unDuplicateCountSolution2(int *arr, int n)
{
    map<int, bool> aMap;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        aMap[arr[i]] = true;
    }
    return aMap.size();
}
int *inputArr(int &n)
{
    cout << "Nhap do dai mang: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> arr[i];
    }
    return arr;
}
int main()
{
    // int arr[] = {1, 2, 16, 16, 5, 16};
    int n = 6;
    int *arr = inputArr(n);
    cout << "Tong cua mang: " << sumOfArray(arr, n) << endl;
    cout << "So phan tu phan biet: " << unDuplicateCountSolution2(arr, n) << endl;
    cout << "So lon nhat mang: " << maxOfArray(arr, n) << endl;
    cout << "in nguoc: ";
    printReverseArray(arr, n);

    return 0;
}
