#include <stdio.h>
int main()
{
    
    int x;
    scanf("%d",&x);
    int mu = x%10;
    int output = 0;
    do
    {
        int donvi =  x%10;
        x = x/10;
        int pow = 1;
        for (int i = 0; i < mu; i++)
        {
            pow = pow * donvi;
        }
        output = output + pow;
    } while (x!=0);
    printf("%d", output);
    return 0;
}
