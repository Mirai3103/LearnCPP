#include <stdio.h>


int demsochuso(int n)
{
    return n==0?0:1+demsochuso(n/10);
}
int perfectNumber(int x){
    int sochuso = demsochuso(x);
    int motnua = sochuso/2;
    sochuso /=2;
    if(sochuso%2==0){
        int tongdau=0;
        int tongsau = 0;
        while (motnua--)
        {
            tongdau= tongdau+ x%10;
            x/=10;
        }
        while (sochuso--)
        {
            tongsau= tongsau+ x%10;
            x/=10;
        }
        return tongdau == tongsau;
        
    }
    return 0;
}
int main()
{

    int x;
    scanf("%d", &x);
    
    return 0;
}
