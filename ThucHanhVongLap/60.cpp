
#include <stdio.h>
double ex(int x)
{
    double s = 0;
    double sohang = 1;
    int giaithua = 1;
    int i = 1;
    while (sohang > 0.0001)
    {

        s = s + sohang;
        giaithua = giaithua * i;
        sohang = x * 1.0 / giaithua;
        i++;
    }
    return s;
}
int main()
{
    int x;
    scanf("%d", &x);

    printf("e(%d)=%lf", x, ex(x));

    return 0;
}
