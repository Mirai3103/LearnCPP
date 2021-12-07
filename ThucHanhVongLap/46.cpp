#include <iostream>
using namespace std;
int main()
{
    int n ,x;
    cin >> n >> x;
    int Xmu2 =x*x;
    double before = 1.0/x;
    int s=0;
    for (int i = 1; i <=n; i++)
    {
        before*=Xmu2;
        s+= before;
        
    }
    cout <<"\n"<< s;
    return 0;
}
 