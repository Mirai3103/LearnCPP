#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int donvi;
    int S = 0;
    while (n!=0)
    {
        donvi = n%10;
        n =n/10;
        if(donvi%2==1){
            S = S+donvi;
        }
    }
    cout << S;
    
    
    
    return 0;
}
