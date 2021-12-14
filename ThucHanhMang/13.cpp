#include <iostream>
#include <algorithm>
using namespace std;

void taosanNt(bool SanNt[]){
    // gia su ban dau tat ca cac so la so nt
    for (int i = 0; i < 100; i++)
    {
        SanNt[i] = true;
    }
    
    for (int i = 2; i <100; i++)
    {
        if (SanNt[i])
        {
            for (int j = 2; j*i < 100; j ++)
            {
                SanNt[j*i] = false;
            }
        }
    }

}
int xuatsanNT(bool arr[], int &n){
    cin >>n;
    int i = 2;
    while (n >0)
    {
       if(arr[i]){
           cout << i <<" ";
           n--;
       }
       i++;
    }
    
    
}
int main(int argc, char const *argv[])
{
    int n;
    bool SanNt[100] ;
    taosanNt(SanNt)  ;
    xuatsanNT(SanNt,n);
    return 0;
}
