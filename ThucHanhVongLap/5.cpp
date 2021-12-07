#include <iostream>
using namespace std;
int dequi(int n){
    int donvi = n%10;
    n = n /10;
    return n==0?donvi: donvi + dequi(n);
}
int main()
{
    int n;
    cin >> n;
    int donvi, s=0;
    // cout <<"tong cac chu so:"<<dequi(n); 
    while (n!=0)
    {
        donvi = n%10;
        n =n/10;
        s =s+donvi;
    }
    cout <<"tong cac chu so:"<<s; 
    
    
    
    return 0;
}
