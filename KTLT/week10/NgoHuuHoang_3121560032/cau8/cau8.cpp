#include <iostream>
#include <math.h>
using namespace std;

int tongUoc(int n)
{
    int sum = 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
        {
            if (i * i == n)
                sum += i;
            else
                sum = sum + i + n / i;
        }
    return sum + 1;
}

void timCacSo(int n = 1000000)
{
    for (int i = 1; i < n; i++) // O(n)
    {
        int tongUoc1 = tongUoc(i);        // O(sqrt(n))
        int tongUoc2 = tongUoc(tongUoc1); // O(sqrt(n))

        if (tongUoc2 == i && tongUoc1 > i)
        {
            cout << i << " - " << tongUoc1 << endl;
        }
    }
}

int main()
{
    timCacSo();
    return 0;
}