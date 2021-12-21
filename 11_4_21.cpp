#include <stdio.h>
int TinhYnKhongDeQui(int n){
     if(n<=3 && n>0){
        return n;
    }
    int y1 =1, y2 =2, y3=3, Yn;
    for (int i = 4; i <= n; i++)
    {
        Yn = y1 +2*y2+3*y3;
        y1 = y2;
        y2 = y3;
        y3 = Yn;
    }
    return Yn;
    
}
int giaithua(int n){return n<2?1:n*giaithua(n-1);}

int TinhYnBangDeQui(int n){
    if(n<=3 && n>0){
        return n;
    }
    return TinhYnBangDeQui(n-1)+ 2*TinhYnBangDeQui(n-2)+ 3*TinhYnBangDeQui(n-3);
    
}

int main()
{

}
