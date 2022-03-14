#include <iostream>
using namespace std;

int FibonacciRecursion(int n)
{
    static int arr[100] = {1, 1};
    if (n > 100)
        return FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
    if (arr[n] == 0)
    {
        arr[n] = FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
    }
    return arr[n];
}

int DecToBin(int n)
{
    if (n == 0)
        return 0;
    return n % 2 + 10 * DecToBin(n / 2);
}
int DecToBinRecursion(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + 10 * DecToBinRecursion(n / 10);
}
int Yn(int n);
int Xn(int n);
void show(int *arr, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
void Backing(int i, int n)
{
    static int x[100];
    for (int j = 0; j < 2; j++)
    {
        x[i] = j;
        if (i > n)
        {
            show(x, n);
            return;
        }
        else
        {
            Backing(i + 1, n);
        }
    }
}
// tìm giá trị lớn nhất của mảng sử dụng đệ qui
int Max(int *arr, int l, int r)
{
    if (l == r)
        return arr[l];
    int mid = (l + r) / 2;
    int maxLeft = Max(arr, l, mid);
    int maxRight = Max(arr, mid + 1, r);
    if (maxLeft > maxRight)
    {
        return maxLeft;
    }
    else
    {
        return maxRight;
    }
}
int BinarySearch(int *arr, int l, int r)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == mid)
            return mid;
        else if (arr[mid] > mid)
            return BinarySearch(arr, l, mid - 1);
        else
            return BinarySearch(arr, mid + 1, r);
    }
    else
    {
        return -1;
    }
}
// tích 2 số lơn sử dụng để qui
int Multiply(int *a, int *b, int *c, int n)
{
    if (n == 0)
        return 0;
    int mid = n / 2;
    int p1 = Multiply(a, b, c, mid);
    int p2 = Multiply(a + mid, b + mid, c + mid, n - mid);
    int p3 = 0;
    for (int i = 0; i < mid; i++)
    {
        p3 += a[i] * b[i];
    }
    for (int i = mid; i < n; i++)
    {
        p3 += a[i] * b[i];
    }
    for (int i = 0; i < n; i++)
    {
        c[i] = p1 + p2 + p3;
    }
    return p1 + p2 + p3;
}
int An(int n)
{
    if (n == 1)
        return 1;
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        s += n * An(n - i);
    }
    return s;
}
// convert  An(n) using Linear recursion

int main()
{
    // int arr[] ={1,4,111,16,12,20,22,0,100,11,18};
    // cout << Max(arr,0,10);
    cout << An(4);
    return 0;
}

int Xn(int n)
{
    if (n == 0)
        return 1;
    return Xn(n - 1) + Yn(n - 1);
}
int Yn(int n)
{
    if (n == 0)
        return 1;
    return 3 * Xn(n - 1) + 2 * Yn(n - 1);
}