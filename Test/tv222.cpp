#include <stdio.h>
int main()
{
    
    int n;
    scanf("%d",&n);
    double output =0; 
    double mau = 0;
    for (double i = 1; i <= n; i++)
    {
        mau = mau + 1/i;
        output = output + i/mau;
    }
    printf("%f",output);
    return 0;
}
