#include <iostream>
#include <stdio.h>
using namespace std;

int BCNN(int a, int b)
{
    int c = a > b ? a : b;
    int d = a > b ? b : a;
    int i = 1;
    while (true)
    {
        c = c * i;
        if (c % d == 0)
        {
            return c;
        }
        i++;
    }
    return c * d;
}
int UCLN(int a, int b)
{
    while (a * b != 0)
    {
        if (a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    return a + b;
}

struct phanso
{
    int tu;
    int mau;
    phanso(int a, int b)
    {
        tu = a;
        mau = b;
    }
    phanso()
    {
        tu = 0;
        mau = 1;
    }
    // operator overloading
    phanso operator+(phanso a)
    {
        int MSC = BCNN(a.mau, this->mau);
        phanso sum((MSC / a.mau) * a.tu + (MSC / this->mau) * this->tu, MSC);
        return sum;
    }
    bool operator<(phanso a){
        return (a.tu * 1.0 / a.mau - this->tu * 1.0 / this->mau) < 0;
    }
    bool operator>(phanso a){
        return (this->tu * 1.0 / this->mau-a.tu * 1.0 / a.mau ) > 0;
    }
    bool operator==(phanso a){
        return (this->tu * 1.0 / this->mau-a.tu * 1.0 / a.mau ) == 0;
    }
};

void inputArray(phanso *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nhap phan so thu " << i + 1 << " (a/b): ";
        scanf("%d/%d", &(arr[i].tu), &(arr[i].mau));
    }
}

void rutgonphanso(phanso &a)
{
    int UC = UCLN(a.tu, a.mau);
    a.tu = a.tu / UC;
    a.mau = a.mau / UC;
}
void tongcacphansotrongmang(phanso *arr, int n, phanso &sum)
{
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        rutgonphanso(sum);
    }
}

void swap(phanso &a, phanso &b)
{
    phanso c = a;
    a = b;
    b = c;
}
void sort(phanso *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i]> arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
void xuatmang(phanso *a, int n)
{
    cout << "\nxuat mang phan so: \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i].tu << "/" << a[i].mau << "; ";
    }
}
int main()
{
    int n;
    cout << "nhap so phan tu: ";
    cin >> n;
    phanso *arr = new phanso[n];
    inputArray(arr, n);
    phanso sum;
    tongcacphansotrongmang(arr, n, sum);
    cout << "tong: " << sum.tu << "/" << sum.mau;
    sort(arr, n);
    xuatmang(arr, n);
    delete[] arr;
    arr = nullptr;
    return 0;
}
