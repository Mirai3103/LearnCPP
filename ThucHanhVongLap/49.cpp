#include <iostream>
using namespace std;
int kieudequi(int n , int x)
int main()
{
    int n,x;
    cin >>x>>n;
    double s =0;
    int tu =1;
    int mau = 0;
    for (int i = 1; i <= n; i++)
    {
        tu*=x;
        mau+=i;
        s+=1.0*tu/mau;

    }
    cout <<"kq:"<<s;
    return 0;
}
