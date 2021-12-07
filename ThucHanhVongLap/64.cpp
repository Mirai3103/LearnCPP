#include <stdio.h>

int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    int s = 0;
    int i = 0;
    do
    {   
        s = s + i;
        i++;
    } while (s+i < n);

    printf("%d va %d", s,n);
        return 0;
}
