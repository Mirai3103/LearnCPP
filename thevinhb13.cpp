// #include <stdio.h>

// int florentino(int n){
//     return n<=2?1:florentino(n-1)+florentino(n-2);
// }
// double tinhs(int n){
//     return n==1?0.5:(n*1.0/(1+florentino(n)))+tinhs(n-1);
// }
// int main()
// {
//     printf("%f", tinhs(2));
//     return 0;
// }
#include <stdio.h>
#include <stdbool.h>

int f(int n)
{
    if (n == 1 || n == 2)return 1;
    return f(n - 1) + f(n - 2);
}

float total(int n)
{
    float S = 0;
    for (float i = 1; i <= n; i++)
    {
        S = S + i / (1 + f(i));
    }
    return S;
}

int main(int argc, char **argv)
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("%f", total(n));
    return 0;
}