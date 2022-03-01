// Ngo Huu Hoang
#include <iostream>
#include <string.h>
using namespace std;

int BunnyEars(int line) // EX 2.2
{
    if (line == 0)
        return 0;
    int count = 2;
    if (line % 2 == 0)
        count = 3;
    return count + BunnyEars(line - 1);
}

int CountHi(char str[], int l) // EX 2.3
{
    if (l <= 1)
        return 0;
    if (str[l - 1] == 'i')
    {
        if (str[l - 2] == 'h')
        {
            if (l == 2)
                return 1;

            if (str[l - 3] == 'x')
            {
                return 0 + CountHi(str, l - 3);
            }
            else
            {
                return 1 + CountHi(str, l - 2);
            }
        }
    }
    return 0 + CountHi(str, l - 1);
}
int Triangle(int height)
{ // EX 2.3
    if (height == 0)
        return 0;
    return height + Triangle(height - 1);
}
int main()
{
    // EX 2.1
    cout << BunnyEars(2) << endl; // 5
    // EX 2.3
    cout << Triangle(2) << endl; // 3

    // EX 2.2
    // char a[100];
    // fflush(stdin);
    // cin.getline(a, 100);
    // int n = strlen(a);
    char a[] = "xhixhihi";
    int n = 8;
    cout << CountHi(a, n); // 1
    return 0;
}
