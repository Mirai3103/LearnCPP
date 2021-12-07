#include <iostream>
using namespace std;

int main()
{
    int n,x, donvi;
    cin >> n>>x;

    bool soki = true;
    while (n!=0&&soki)
    {
        
        donvi = n % 10;
        n = n / 10;
        if(donvi == x) soki = false;

    }
    if (soki)
    {
        cout << "dung ";
    }
    else
    {
        cout << "sai";
    }
    return 0;
}
