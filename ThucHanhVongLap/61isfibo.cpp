#include <stdio.h>


// int sofibothun(int n ){
//     if(n <=2) return 1;
//     return sofibothun(n-1)+sofibothun(n-2);
// }
bool isFibo(int n){
    if(n==1) return true;
    int x3;
    int x1=1, x2 = 1;
    
    do
    {
        x3 = x2 + x1;
        x1= x2;
        x2 = x3;
        if(n == x3){
            return true;
        }
    } while (x3<n);
    return false;
}
int main()
{
    int n;
    scanf("%d",&n);
   

    if(isFibo(n)){
        printf("%d la so fibonacci",n);
    }
    else{
        printf("%d ko phai la so fibonacci",n);
    }
    return 0;
}
