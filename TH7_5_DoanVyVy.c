#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuanHoaXau(char str[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tolower(str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] != '\0')
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
            }
            if (str[i - 1] == ' ' || i == 0)
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                {
                    str[i] -= 32;
                }
            }
        }
    }
    while (str[0] == ' ')
    {
        for (int i = 0; i < n; i++)
        {
            str[i] = str[i + 1];
            str[n - 1] = '\0';
        }
    }
    while (str[n - 1] == ' ')
    {
        str[n - 1] = '\0';
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            for (int j = i; j < n - 1; j++)
            {
                str[j] = str[j + 1];
            }
            str[n - 1] = '\0';
            i--;
        }
    }
    str[n-1] = '\0';
}

void tachTen(char hoTen[], char hoLot[], char ten[], int n)
{
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        if (hoTen[i] = ' ')
        {
            break;
        }
    }
    for (int j = 0; j < i; j++)
    {
        hoLot[j] = hoTen[j];
    }
    hoLot[i] = '\0';
    for (int j = i + 1; j < n; j++)
    {
        ten[j - i - 1] = hoTen[j];
    }
    ten[n - i - 1] = '\0';
}
int main()
{
    char hoTen[100], hoLot[50], ten[50];
    fgets(hoTen, sizeof(hoTen)/sizeof(hoTen[0]), stdin);
    int n = strlen(hoTen);
    puts(hoTen);
    chuanHoaXau(hoTen, n);
    puts(hoTen);
    tachTen(hoTen, hoLot, ten, n);

    puts(hoLot);
    puts(ten);
    return 0;
}