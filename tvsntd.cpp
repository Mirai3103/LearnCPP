#include <stdio.h>
#include <math.h>

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
        printf("\na[%d]=%d", i, a[i]);
    }
}

bool snt(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool daosnt(int n)
{
    
        int a, b = 0;
        if (snt(n))
        {
            while (n > 0)
            {
                a = n % 10;
                b = b * 10 + a;
                n = n / 10;
            }
            // printf("-b-%d", n);
            if (snt(b))
                return true;
            return false;
        }
    
    return false;
}

void sapxep(int a[], int &n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(int argc, char **argv)
{
    int tien$ =2;
    int n;
    printf("Nhap do dai cua mang : ");
    scanf("%d", &n);
    int a[n];
    nhapmang(a, n);
    xuatmang(a, n);
    bool khongtontai = true;
    printf("\nCac so sau khi dao van la so nguyen to la: ");
    for (int i = 0; i < n; i++)
    {
        if (daosnt(a[i]))
        {
            printf("%d; ", a[i]);
            khongtontai = false;
        }
    }
    if (khongtontai == true)
        printf("\nKhong ton tai");
    printf("\nSau khi sap xep theo chieu tang dan");
    sapxep(a, n);
    xuatmang(a, n);

    
    return 0;
}