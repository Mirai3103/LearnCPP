#include <stdio.h>
#include <math.h>
int main(int argc, char **argv)
{
    for (int i = 10000; i < 100000; i++)
    {
        int i1 = i;
        int i2 = i;
        bool isprime = true;
        for (int a = 2; a <= sqrt(i); a++)
        {
            if (i % a == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime)
        {
            int b = 0;
            while (i2!=0)
            {
                int t = 0;
                t = i2 % 10;
                i2 = i2 / 10;
                b = b * 10 + t;
             }
            if (i1 == b)
            {
                printf("%d\n", b);
            }
        }
        
    }
    return 0;
}