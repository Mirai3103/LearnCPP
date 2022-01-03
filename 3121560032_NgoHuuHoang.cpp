/*
Nhom: 17
Ma sinh vien: 3121560032
Ten sinh vien: Ngo Huu Hoang
*/
#include <iostream>
using namespace std;
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
int kt_Kitu(char c);
void dayCollatz(int n);
void capnhatGT(int a[]);
void vedothi(int a[], int k = 20); // khong nhap k thi k = 20;
void taoMang(int a[]);
void timMinMax(int a[]);
void xuat(int a[]);
int nhapSoNguyenDuong(){
    int n;
    do{
        cin >> n;
    }while(n <=0);
    return n;
}
int main()
{
    // Dien thong tin cua sinh vien
    cout << "Nhom: 17"
         << "\t "
         << "3121560032"
         << "\t\t"
         << "Ngo Huu Hoang"
         << "\n";
    cout << fixed << setprecision(1);
    // test bai 1
    printf("\n // test bai 1 \n");
    printf("bai 1  moi ban nhap ki tu: ");
    char c;
    cin >> c;
    int kiemtra = kt_Kitu(c);
    if (kiemtra == 1)
    {
        printf("%c la ki tu chu In hoa\n", c);
    }
    else
    {
        if (kiemtra == 0)
        {
           printf("%c khong phai ki tu chu\n", c);
        }
        else
        {
            printf("%c la ki tu chu thuong\n", c);
        }
    }
    printf("\n // test bai 2 \n");
    int n;
    printf("bai 2 Nhap n: ") ;
    cin >> n;
    dayCollatz(n);
    printf("\n // test bai 3 \n");
    // test bai 3
    printf("\n");
    int arr[9];
    taoMang(arr); // dat tat ca phan tu bang 0;
    capnhatGT(arr);
    xuat(arr);
    vedothi(arr);
    return 0;
}

int kt_Kitu(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 2;
    }
    else
    {
        if ((c >= 'A' && c <= 'Z'))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
void dayCollatz(int n)
{

    if (n == 1)
    {
        printf("1") ;
    }
    else
    {
        printf("%d ", n);
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = n * 3 + 1;
        }
        dayCollatz(n);
    }
}

void taoMang(int a[])
{
    for (int i = 0; i < 9; i++)
    {
        a[i] = 0;
    }
}
void capnhatGT(int a[])
{

    for (int i = 2; i < 8; i++)
    {
        printf( "Nhap so ca moi trong ngay thu %d: ", i );

        a[i] += nhapSoNguyenDuong();
    }
    printf("Nhap so ca moi trong ngay thu chu nhat: ") ;

    a[8] += nhapSoNguyenDuong();
    timMinMax(a); // sau khi cap nhat thi cap nhat luon min max
}
void timMinMax(int a[])
{
    int soCaMax = a[2];
    int soCaMin = a[2];
    for (int i = 3; i < 9; i++)
    {
        if (a[i] > soCaMax)
        {
            soCaMax = a[i];
        }
        if (a[i] < soCaMin)
        {
            soCaMin = a[i];
        }
    }
    a[0] = soCaMax;
    a[1] = soCaMin;
}
void xuat(int a[])
{
    printf("\n");
    printf("GTLN \t");
    printf("GTNN \t");
    for (int i = 2; i < 8; i++)
    {
        printf("Thu %d\t",i);
    }
    printf("Chu nhat\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%4d\t", a[i]);
    }
}
void vedothi(int a[], int k)
{ // co the nhap k hoac khong
    printf("\nVe bieu do\n");
    int end = 0;
    for (int i = 2; i < 8; i++)
    {
        printf("Ngay thu %d: ",i);
        end = a[i] / k;
        for (int j = 0; j < end; j++)
        {
            printf("*") ;
        }
        printf("\n");
    }
    printf("Chu nhat  : ");
    end = a[8] / k;
    for (int j = 0; j < end; j++)
    {
        printf("*") ;
    }
 
}