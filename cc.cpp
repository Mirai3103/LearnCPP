#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define max 100
int n;
char s[max];

void nhapchuoi(char *s)
{
    printf("Nhap chuoi: ");
    gets(s);
    n = strlen(s);
}
void xuatchuoi(char *s);
int demkytuinhoa(char *s);
int demkytuinthuong(char *s);
int demsotu(char *s);
void tansocackytu(char *s);
bool check(char *s, int index, int x);
void hienthiascii(char *s, int n);
char *tachmottubentrai(char *s);
char *tachmottubenphai(char *s);
void sapxepascii(char *s);
void ChuanHoa(char *s);
int timViTri(char s, int length);
void hienThiTu(char *s, int pos, int length);
bool khoangTrang(char c);
int timViTri(char *s, int *length);

int main(int argc, char **argv)
{
    int n;
    char s[n];
    nhapchuoi(s);
    xuatchuoi(s);
    printf("\nSo ky tu in hoa trong mang la: %d", demkytuinhoa(s));
    printf("\nSo ky tu in thuong trong mang la: %d", demkytuinthuong(s));
    tansocackytu(s);
    hienthiascii(s, n);
    int len = 0;
    int pos = timViTri(s, &len);
    hienThiTu(s, pos, len);
    printf("\nTu dau tien ben phai la: %s", tachmottubenphai(s));
    printf("\nTu dau tien ben trai la: %s", tachmottubentrai(s));
    ChuanHoa(s);
    getchar();
    sapxepascii(s);
    return 0;
}

//

void xuatchuoi(char *s)
{
    printf("\nChuoi da nhap: ");
    puts(s);
}

int demkytuinhoa(char *s)
{
    int dem = 0;
    while (*s)
    {
        if (isupper(*s))
            dem++;
        s++;
    }
    return dem;
}

int demkytuinthuong(char *s)
{
    int dem = 0;
    while (*s)
    {
        if (islower(*s))
            dem++;
        s++;
    }
    return dem;
}

int demsotu(char *s)
{
    int l = strlen(s), d = 1;
    for (int i = 0; i < l; i++)
        d++;
    return d;
}

void tansocackytu(char *s)
{
    int n;
    int l = strlen(s);
    int d[255];
    for (int i = 0; i < demsotu(s); i++)
        d[s[i]] = 0;
    for (int i = 0; i < (demsotu(s)); i++)
        d[s[i]]++;
    for (int i = 0; i < (demsotu(s)); i++)
        if (d[s[i]] != 0)
        {
            printf("\n %c xuat hien %d lan cuoi ", s[i], d[s[i]]);
            d[s[i]] = 0;
        }
}

bool check(char *s, int index, int x)
{
    int i;
    for (i = 0; i < index; i++)
    {
        if (s[i] == x)
        {
            return true;
        }
    }
    return false;
}

void hienthiascii(char *s, int n)
{
    int i;
    for (i = 0; i < demsotu(s); i++)
    {
        if (!check(s, i, s[i]))
        {
            printf("\nKy tu %c ma ascii tuong ung la %i", s[i], s[i]);
        }
    }
}

char *tachmottubentrai(char *s)
{
    return strrev(strrchr(strrev(s), ' ') + 1);
}

char *tachmottubenphai(char *s)
{
    return strrchr(s, ' ') + 1;
}

void sapxepascii(char *s)
{
    int n;
    char temp;
    for (int i = 0; i < strlen(s) - 1; i++)
        for (int j = i + 1; j < strlen(s); j++)
            if (*(s + i) > *(s + j) && *(s + i) != ' ' && *(s + j) != ' ')
            {
                temp = *(s + i);
                *(s + i) = *(s + j);
                *(s + j) = temp;
            }
    printf("\nThu tu chu cai duoc sap xep theo ascii: ");
    for (int i = 0; i < n; i++)
    {
        printf("\t%c", temp);
    }
}

void ChuanHoa(char *s)
{
    int n, i;
    if ((s[0] >= 'a') && (s[0] <= 'z'))
        s[0] -= 32;
    for (i = 1; i < n; i++)
        if ((s[i - 1] == ' ') && (s[i] != ' ') && (s[i] >= 'a') && (s[i] <= 'z'))
            s[i] -= 32;
    for (i = 1; i < n; i++)
        if ((s[i - 1] != ' ') && (s[i] != ' ') && (s[i] >= 'A') && (s[i] <= 'Z'))
            s[i] += 32;
    printf("%c", s[0]);
    for (i = 1; i < n; i++)
    {
        if (s[i] == ' ')
        {
            if (s[i - 1] != ' ')
                printf("%c", s[i]);
        }
        else
            printf("%c", s[i]);
    }
}

bool khoangTrang(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

void hienThiTu(char *s, int pos, int length)
{
    printf("\nTu dai nhat: \'");
    int i;
    for (i = pos; i < pos + length; i++)
    {
        printf("%c", s[i]);
    }
    printf("\'\nDo dai: %d\nVi tri cua tu: %d", length, pos);
}

int timViTri(char *s, int *length)
{
    int len = 0;
    int lenMax = 0;
    int pos = 0;
    int posCurrent = 0;
    int size = strlen(s);
    int i;
    for (i = 0; i < size; i++)
    {
        if (!khoangTrang(s[i]))
        { // hello ..
            posCurrent = i - len;
            len++;
        }
        else
        {
            if (len > lenMax)
            {
                lenMax = len;
                pos = posCurrent;
            }
            len = 0;
        }
    }

    *length = lenMax;
    return pos;
}