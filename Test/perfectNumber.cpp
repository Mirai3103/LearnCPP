#include <stdio.h>

int main(int argc, char **argv)
{
    int n, n1, i;
    int tong = 0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            tong = tong + i;
        }
    }
    if (tong == n)
    {
        printf("%d la so hoan hao", n);
    }
    else
        printf("%d la so khong hoan hao", n);
    return 0;
}