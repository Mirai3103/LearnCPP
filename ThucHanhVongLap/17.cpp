#include <iostream>
using namespace std;

int ULLN(int n)
{
    if(n%2==1) return n;
    for (int i = n/2; i >=1; i--)
    {
        if(n%i==0&&i%2==1){
            return i;
        }
    }
    return 1;
    
}
int main()
{
    int a;
    cin >> a ;
    cout << "ULLN: " << ULLN(a);
    return 0;
}