#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int wordCount(char *s)
{
    int count = 0;
    while (*s == ' ')
        s++;
    if (*s == '\0')
        return 0;
    while (*s != '\0')
    {
        if (*s == ' ' && *(s + 1) != ' ' && *(s + 1) != '\0')
            count++;
        s++;
    }
    return ++count;
}

char *subString(char *s, int pos, int n)
{
    int i = 0;
    int j = 0;
    char *rs = new char[n + 1];
    while (i < pos && s[i] != '\0')

        i++;

    if (s[i] == '\0')

        return rs;

    for (; j < n; j++, i++)
    {
        if (s[j] == '\0')
            break;
        rs[j] = s[i];
    }
    rs[j] = '\0';
    return rs;
}

int maxLengthWord(char *s)
{
    int max = 0;
    char *t = new char[strlen(s)];
    int i = 0;
    int length = 0;
    while (s[i] != '\0')
    {

        length = 0;
        if (s[i] != ' ')
        {
            int start = i;
            while (s[i] != ' ' && s[i] != 0)
            {
                length++;
                i++;
            }
            if (length > max)
            {
                max = length;
                memcpy(t, &s[start], length);
            }
        }
        i++;
    }
    cout << t << endl;
    return length;
}

int main()
{
    char s[] = "    ngo              huu hoangs    d    ";
    cout << wordCount(s) << endl;
    maxLengthWord(s);
    cout << subString(s, 1, 3) << endl;
    return 0;
}
