#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s[100];
    char c;
    FILE *fi = fopen("a.txt", "r");
    FILE *fo = fopen("out.txt", "w");
    int count = 0;
    while (!feof(fi))
    {
        fscanf(fi, "%c", &c);
        printf("%c", c);
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            /* code */ count++;
        }
    }
    fprintf(fo, "%d", count);

    return 0;
}
