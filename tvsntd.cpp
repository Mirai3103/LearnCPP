#include <iostream>
using namespace std;
#include <cstring>
void e(char const s[])
{
    int cnt, k;
    char str[100];
    int newlength = 0;
    int i = 0;
    while (s[i] != '\0' && s[i] != ' ')
    {
        i++;
    }
    memcpy(str, s, i + 1);
    newlength += (i + 1);
    while (s[i] != '\0')
    {

        if (s[i] == ' ')
        {
            k = i;
        }
        i++;
    }
    memcpy(str + newlength, s + k + 1, i - k + 1);
    newlength = newlength + i - k + 1;
    str[newlength] = '\0';
    i = 0;
    while (str[i] != '\0')
    {
        cout << str[i];
        i++;
    }
}

int main()
{
    char s[] = "ngo huu hoang";
    e(s);
}
