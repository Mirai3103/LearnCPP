#include <iostream>
using namespace std;
int main()
{
    int n ,x;
    cin >> n >> x;
    int Xmu2 =x*x;
    int before = 1;
    int s=0;
    for (int i = 1; i <=n; i++)
    {
        before*=Xmu2;
        s+= before;
        
    }
    cout <<"\n"<< s;
    return 0;
}
 