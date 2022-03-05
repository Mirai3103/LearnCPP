#include <iostream>
using namespace std;


long decToBin(int n)
{
    if (n == 0)
        return 0;
    return (n % 2 + 10 * decToBin(n / 2));
}

int main()
{
    int n;
    do
    {
        cin >> n;
    } while (n<0);
    
    cout << decToBin(2);
}