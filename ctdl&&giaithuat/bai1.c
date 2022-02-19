#include <stdio.h>

float tinhtong(int x){
    float s = 0;
    
    float tu = x;
    float mau = 1;
    float next = tu / mau;
    int i =  1;
    while (next > 0.000001)
    {
        s = s + next;
        tu = tu * x*x;
        i++;
        mau = mau * i;
        i++;
        mau = mau * i;
        next = tu/mau;
        

    }
    return s;
    
}
int main(int argc, char const *argv[])
{
    printf("%f",tinhtong(10));
    return 0;
}
