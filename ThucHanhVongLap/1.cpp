#include <iostream>
using namespace std;
int dequi(int n){
    int donvi = n%10;
    n = n /10;
    return n==0?donvi:dequi(n);
}
int main()
{
    int n;
    cin >> n;
    int donvi;
    // cout <<"chu so dau:"<<dequi(n); 
    while (n!=0)
    {
        donvi = n%10;
        n =n/10;
    }
    cout <<"chu so dau:"<<donvi; 
    
    
    return 0;
}
