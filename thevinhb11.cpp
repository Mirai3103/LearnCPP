#include <stdio.h>

// struct capso
// {
//      int xi;
//      int tongtruoc;
// };
// capso bai11(int n){
    
//     return n==1?1:n*(bai11(n-1));
// }

int main()
{
    int n;
    scanf("%d",&n);
    int tongtruoc = 0;
    int xi = 1;
    for (int i = 2; i <= n; i++)
    {
        tongtruoc = tongtruoc+xi;
        xi = i*tongtruoc; 
    }

    printf("so vi tri %d la: %d",n,bai11(5));
    return 0;
}
