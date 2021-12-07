#include <stdio.h>

int tonguoc(int n)
{

    int s = 1;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            s = s + i;
    }
    return s;
}

int main()
{

    int max = 1000000;
    for (int i = 2; i < max; i++)
    {
        int tong = tonguoc(i);
        if(tong <= i){
            continue;
        }
        if (tong < max && tonguoc(tong)==i){
            printf("%d va %d \n", i, tong);
        }
    }

    return 0;
}
