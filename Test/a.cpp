#include <stdio.h>

#include <ctime>
int main()
{
    const int MAXLEN = 80;
    char s[MAXLEN];
    time_t t = time(0);
    strftime(s, MAXLEN, "%m/%d/%Y", localtime(&t));
    printf("Current local time and date: %s", s);

    return 0;
}