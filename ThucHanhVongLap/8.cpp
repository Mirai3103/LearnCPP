#include <iostream>
using namespace std;

int main()
{
    int n,i,donvi;
    cin >> n;
    cin >> i;
 
    bool tontai = true;
    while (i)
    {
        if(n==0){
            tontai = false;
        }
        donvi = n%10;
       n = n/10;
       i--;
    }
    if(tontai){
        cout <<"so can tim : "<< donvi;
    }else
    {
        cout <<"khong the tim";
    }
    
    
    
    
   
    
    
    return 0;
}
