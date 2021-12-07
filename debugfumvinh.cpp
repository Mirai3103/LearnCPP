
#include <stdio.h>
#include <math.h>

void nhapmang(int a[], int &n);
void xuatmang(int a[], int &n);
int gtnn(int a[], int n);

int main(int argc, char **argv)
{
    int n;
    printf("Nhap do dai cua mang: ");
    scanf("%d", &n);
    int a[n];
    nhapmang(a, n);
    xuatmang(a, n);
    int gtn = gtnn(a, n);
    printf("\nPhan tu nguyen to nho nhat co gia tri la: %d", gtn);
    return 0;
}

void nhapmang(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\na[%d]= ", i);
        scanf("%d", &a[i]);
    }
}

void xuatmang(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\na[%d]= %d", i, a[i]);
    }
}

bool snt(int n)
{
    if (n == 2)
        return true; // thêm dòng này
    if (n <= 1)
        return false;
    for (int i = 2 /*khai bao i =2 chu may*/; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int gtnn(int a[], int n)
{
    int min = a[0];
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= min)
        {
            if (snt(a[i]))
            {
                min = a[i];
                c = i;
            }
        }
    }
    return ++c;
}