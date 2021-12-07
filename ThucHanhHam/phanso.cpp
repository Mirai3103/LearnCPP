#include <stdio.h>

int UCLN(int a, int b)
{
    int ucln = 1;
    for (int i = a > b ? b : a; i > 1; i--)
    {
        if (a % i == 0)
        {
            if (b % i == 0)
            {
                ucln = i;
                break;
            }
        }
    }
    return ucln;
}

void rutgon(int &tu, int &mau)
{
    int ucln = UCLN(tu, mau);
    tu = tu / ucln;
    mau = mau / ucln;
}
int boichungnhonhat(int a, int b)
{
    int bcln = a > b ? a : b;
    if (b % a == 0 || b % a == 0)
        return bcln;
    bcln = bcln * 2;
    do
    {
        if (bcln % a == 0)
        {
            if (bcln % b == 0)
            {
                return bcln;
            }
        }
        bcln++;
    } while (true);

    return bcln;
}
void cong2phanso(int a, int b, int c, int d)
{

    int mausochung = boichungnhonhat(b, d);
    int e, f = mausochung;
    e = a * (mausochung / b) + c * (mausochung / d);
    rutgon(e, f);
    printf("%d/%d + %d/%d  = %d/%d\n", a, b, c, d, e, f);
}
void tru2phanso(int a, int b, int c, int d)
{
    c = -c;
    cong2phanso(a, b, c, d);
}
void nhan2phanso(int a, int b, int c, int d)
{
    int e = a * c;
    int f = d * b;
    rutgon(e, f);
    printf("%d/%d * %d/%d  = %d/%d\n", a, b, c, d, e, f);
}
void chia2phanso(int a, int b, int c, int d)
{
    if(c ==0){
        printf("err: khong the chia cho 0");
        return;
    }
    int e = a * d;
    int f = d * c;
    if(c ==0)
    rutgon(e, f);
    printf("%d/%d : %d/%d  = %d/%d\n", a, b, c, d, e, f);
}
int main()
{
    int a, b=1;
    int c, d=1;
    printf("nhap phan so a/b: \n");
    scanf("%d", &a);
    do
    {
        scanf("%d", &b);
    } while (b == 0);

    printf("nhap phan so c/d: \n");
    scanf("%d", &c);
    do
    {
        scanf("%d", &d);
    } while (d == 0);
    cong2phanso(a, b, c, d);
    tru2phanso(a, b, c, d);
    nhan2phanso(a, b, c, d);
    chia2phanso(a, b, c, d);
    return 0;
}
