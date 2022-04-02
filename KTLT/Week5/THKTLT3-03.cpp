// Cho dãy n phần tử các số nguyên dương. Hãy xóa các số nguyên tố khỏi dãy.

#include <iostream>
using namespace std;
int *createArray(int &n)
{
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> arr[i];
    }
    return arr;
}

void showArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void deletePrime(int *&arr, int &n)
{
    int *newA = new int[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (!prime(arr[i]))
        {
            newA[j] = arr[i];
            j++;
        }
    }
    delete[] arr;
    arr = newA;
    n = j;
}

int main()
{
    int n;
    int *arr = createArray(n);
    showArray(arr, n);
    deletePrime(arr, n);
    showArray(arr, n);
    return 0;
}