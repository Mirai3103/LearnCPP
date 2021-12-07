#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int a, b, c;
    a = n % 10;
    n /= 10;
    b = n % 10;
    n /= 10;
    c = n % 10;

    if (a > b)
    {
        if (a > c)
        {
            printf("so can tao la: %d%d%d", c,b,a);
        }
        else
        {
            printf("hang tran la %d lon nhat,", c);
        }
    }
    else
    {
        if (b > c)
        {
            printf("hang chuc la %d lon nhat,", b);
        }
        else
        {
            printf("hang tran la %d lon nhat,", c);
        }
    }

return 0;
}
