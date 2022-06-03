#include <stdio.h>

int **nhapMaTranVuong(int *n)
{
    int **a, i, j;
    printf("Nhap so hang: ");
    scanf("%d", n);
    a = (int **)malloc(sizeof(int *) * (*n));
    for (i = 0; i < *n; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * (*n));
        for (j = 0; j < *n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    return a;
}

void xuatMaTranVuong(int **a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

void inCacPhanTuOTrenBien(int **a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                printf("%5d", a[i][j]);
            }
        }
    }
}

int caud(int **a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j < i)
            {
                if (a[i][j] != a[j][i])
                    return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n, **a;
    a = nhapMaTranVuong(&n);
    xuatMaTranVuong(a, n);
    printf("\n");
    inCacPhanTuOTrenBien(a, n);
    if (caud(a, n) == 1)
        printf("\nMa tran doi xung");
    else
        printf("\nMa tran khong doi xung");

    return 0;
}