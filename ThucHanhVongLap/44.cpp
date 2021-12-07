#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x,n;
    cout <<"nhap x va n:\n";
    cin >>x>>n;
    int s = 0;
    int before = 1;
    for (int i = 1; i <=n; i++)
    {
        before*=x;
        s += before;
        
    }
    cout << s;
    return 0;
}
