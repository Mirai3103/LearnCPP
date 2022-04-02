/*Cho hai dãy số nguyên a và b; trong đó dãy a có n số, dãy b có m số. Nối dãy b vào sau
dãy a tạo thành dãy c; xuất dãy c lên màn hình.*/
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

int *conCat(int *a, int n, int *b, int m)
{
    int *c = new int[n + m];
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i];
    }
    for (int i = 0; i < m; i++)
    {
        c[n + i] = b[i];
    }
    return c;
}

int main()
{
    int n;
    int *a = createArray(n);
    showArray(a, n);
    int m;
    int *b = createArray(m);
    showArray(b, m);
    int *c = conCat(a, n, b, m);
    int lengthC = n + m;
    showArray(c, lengthC);

    return 0;
}