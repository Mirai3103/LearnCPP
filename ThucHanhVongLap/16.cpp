#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin >> a>>b;
    bool nguyentocungnhau = true;
    for (int i = a>b?b:a; i >=2; i--)
    {
        if(a%i==0 && b%i==0){
            nguyentocungnhau = false;
            break;
        }
    }
    if(nguyentocungnhau){
        cout <<"co nguyen to cung nhau";
    }else
    {
        cout <<"khng phai";
    }
    
    
    return 0;
}
