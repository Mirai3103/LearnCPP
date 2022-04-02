// Cho dãy n phần tử các số nguyên. Hãy xóa phần tử ở vị trí thứ k của dãy.
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

void deleteIndex(int *arr, int n, int k)
{
    for (int i = k; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int n;
    int *arr = createArray(n);
    showArray(arr, n);
    int k;
    cout << "Nhap vi tri muon xoa: ";
    cin >> k;
    deleteIndex(arr, n, k);
    showArray(arr, n - 1);
    return 0;
}