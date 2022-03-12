// Câu 2: In đảo ngược số nguyên dương n. Ví dụ: n=1234, in ra 4321.

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
    int n;
    cin >> n;
    inDaoNguoc(n); // = 4321
    return 0;
}