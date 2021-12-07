#include <stdio.h>

int demsochuso(int n)
{
    return n == 0 ? 0 : (1 + demsochuso(n / 10));
}
int isHappyNumber(int n)
{
    int sochuso = demsochuso(n);
    if (sochuso % 2 == 1)
        return 0;
    int i = sochuso / 2, dv = 0;
    int sum1 = 0, sum2 = 0;
    while (i != 0)
    {
        dv = n % 10;
        n = n / 10;
        sum1 += dv;
        i--;
    }

    while (n != 0)
    {
        dv = n % 10;
        n = n / 10;
        sum2 += dv;
    }
    return sum1 == sum2;
}
int main()
{
    printf("%d\n", isHappyNumber(156435));
    return 0;
}
