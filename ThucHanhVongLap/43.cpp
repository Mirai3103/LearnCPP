#include <iostream>
using namespace std;
int main()
{
    int n ;
    cin >> n;
    int before =1;
    int s=0;
    for (int i = 1; i <=n; i++)
    {
        before*=i;
        s+= before;
        
    }
    cout <<"\n"<< s;
    return 0;
}
