#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >>n;
    double s =0;
    for (int i = 0; i <= n; i++)
    {
        s += (2.0*i+1)/(2*i+2);
    }
    cout <<"kq:"<<s;
    return 0;
}
