#include <iostream>
using namespace std;
string sangchu(int n)
{
    switch (n)
    {
    case 0:
        return "khong ";
    case 1:
        return "mot ";
    case 2:
        return "hai ";
    case 3:
        return "ba ";
    case 4:
        return "bon ";
    case 5:
        return "nam ";
    case 6:
        return "sau ";
    case 7:
        return "bay ";
    case 8:
        return "tam ";
    case 9:
        return "chin ";
    }
    return "khong hop le";
}
void docso(int n)
{
    string chu = "";
    while (n != 0)
    {
        chu = sangchu(n % 10) + chu;
        n = n / 10;
    }
    cout << chu;
}
int main()
{
    docso(1234);
    return 0;
}
