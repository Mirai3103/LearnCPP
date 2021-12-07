#include <stdio.h>

void nhapmang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void xuatmang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d; ", arr[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    nhapmang(arr, n);
    int soday = 0;
    int counter = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            counter++;
        }
        else
        {
            if (counter != 0)
            {
                soday++;
                counter = 0;
            }
        }
    }
    if (counter != 0)
    {
        soday++;
    }
    printf("so day tang: %d\n", soday);
    xuatmang(arr, n);
    return 0;
}
