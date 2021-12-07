#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int donvi;
    bool toansole = true;
    while (n!=0)
    {
        donvi = n%10;
        n =n/10;
        if(donvi%2==0){
            toansole = false;
            break;
        }
    }
    if(toansole){
        cout <<"n toan chu so le";
    }else{
        cout <<"n khong phai toan chu so le";
    }
    
    
    
    return 0;
}
