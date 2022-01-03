#include <iostream>
#include <stdio.h>
using namespace std;


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
int BCNN(int a, int b)
{
    return a*b/UCLN(a,b);
}
struct PhanSo
{
    int Tu;
    int Mau;
    PhanSo(int tu, int mau)
    {
        Tu = tu;
        Mau = mau;
    }
    PhanSo()
    {
        Tu = 0;
        Mau = 1;
    }
    void rutGonPhanSo()
    {
    int UC = UCLN(Tu, Mau);
    Tu = Tu / UC;
    Mau = Mau / UC;
    }
    // operator overloading
    PhanSo operator+(PhanSo a)
    {
        int MSC = BCNN(a.Mau, this->Mau);
        PhanSo sum((MSC / a.Mau) * a.Tu + (MSC / this->Mau) * this->Tu, MSC);
        return sum;
    }
    PhanSo operator-(PhanSo a){
        a.Tu = -1*a.Tu;
        return *this+ a;
    }
    bool operator<(PhanSo a){
        return (a.Tu * 1.0 / a.Mau - this->Tu * 1.0 / this->Mau) < 0;
    }
    bool operator>(PhanSo a){
        return (this->Tu * 1.0 / this->Mau-a.Tu * 1.0 / a.Mau ) > 0;
    }
    bool operator==(PhanSo a){
        return (this->Tu * 1.0 / this->Mau-a.Tu * 1.0 / a.Mau ) == 0;
    }
    bool operator<=(PhanSo a){
        return *this < a || *this==a;
    }
    bool operator>=(PhanSo a){
        return *this > a || *this==a;
    }
    bool operator!=(PhanSo a){
        return !(*this == a);
    }
    void input(){
        scanf("%d/%d", &(Tu), &(Mau));
    }
    void show(){
        printf("%d/%d",Tu,Mau);
    }
};

void inputArray(PhanSo *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nhap phan so thu " << i + 1 << " (a/b): ";
        arr[i].input();
    }
}

void tongCacPhanSoTrongMang(PhanSo *arr, int n, PhanSo &sum)
{
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        sum.rutGonPhanSo();
    }
}

void swap(PhanSo &a, PhanSo &b)
{
    PhanSo c = a;
    a = b;
    b = c;
}
void sort(PhanSo *arr, int n)
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
void xuatMang(PhanSo *a, int n)
{
    cout << "\nxuat mang phan so: \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i].Tu << "/" << a[i].Mau << "; ";
    }
}
int main()
{
    int n;
    cout << "nhap so phan tu: ";
    cin >> n;
    PhanSo *arr = new PhanSo[n];
    inputArray(arr, n);
    PhanSo sum;
    tongCacPhanSoTrongMang(arr, n, sum);
    cout << "tong: " << sum.Tu << "/" << sum.Mau;
    sort(arr, n);
    xuatMang(arr, n);
    delete[] arr;
    arr = nullptr;
    return 0;
}
