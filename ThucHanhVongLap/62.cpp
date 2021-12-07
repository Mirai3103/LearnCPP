#include <stdio.h>
int dequi(int n){
    return n<3?1:dequi(n-1)+dequi(n-2);
}
int main(int argc, char const *argv[])
{   
    printf("; %d;\n", argc);
    int n;
    scanf("%d", &n);
    int x1 = 1, x2 = 1;
    int x3 = 1;
    printf("1; 1; ");
    for (int i = 3; i <= n; i++)
    {
        x3 = x1 + x2;
        printf("%d; ",x3);
        x1 = x2;
        x2 = x3;
    }
    printf("so hang thu %d la: %d", n, x3);

    return 0;
}

