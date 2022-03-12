#include <iostream>
using namespace std;
void inDaoNguoc(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        cout << n % 10;
        inDaoNguoc(n / 10);
    }
}
int main()
{
    inDaoNguoc(1234);
    return 0;
}
