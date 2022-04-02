// Cho dãy n phần tử các số nguyên. Hãy chèn phần tử x vào vị trí thứ k của dãy.

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

void insert(int *&arr, int &n, int k, int x)
{
    int *newA = new int[n + 1];
    for (int i = 0; i < k; i++)
    {
        newA[i] = arr[i];
    }
    newA[k] = x;
    for (int i = k; i < n; i++)
    {
        newA[i + 1] = arr[i];
    }
    delete[] arr;
    arr = newA;
    n++;
}

int main()
{
    int n;
    int *arr = createArray(n);
    showArray(arr, n);
    int k;
    int x;
    cout << "Nhap vi tri muon chen: ";
    cin >> k;
    cout << "Nhap gia tri muon chen: ";
    cin >> x;
    insert(arr, n, k, x);
    showArray(arr, n);
    return 0;
}
