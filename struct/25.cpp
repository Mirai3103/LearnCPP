#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

struct DuongThang
{
    int a;
    int b;
    int c;
};
struct GiaoDiem
{
    int x;
    int y;
    DuongThang * linear1;
    DuongThang * linear2;
};

void input(DuongThang &l)
{
    cout << "Duong thang aX+bY+c=0" << endl;
    cout << "Nhap a: ";
    cin >> l.a;
    cout << "Nhap b: ";
    cin >> l.b;
    cout << "Nhap c: ";
    cin >> l.c;
}
void inputList(DuongThang *l, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Duong thang thu " << i + 1 << endl;
        input(l[i]);
    }
}
void giaoDiem(DuongThang l1, DuongThang l2, GiaoDiem &g)
{
    g.linear1 = &l1;
    g.linear2 = &l2;
    g.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    g.y = (l1.a * l2.c - l2.a * l1.c) / (l2.a * l1.b - l1.a * l2.b);
}
int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
double Goc(GiaoDiem g){
    int cos = (g.linear1->a * g.linear2->a + g.linear1->b * g.linear2->b) / (sqrt(g.linear1->a * g.linear1->a + g.linear1->b * g.linear1->b) * sqrt(g.linear2->a * g.linear2->a + g.linear2->b * g.linear2->b));
    return acos(cos);
}
double *ListGoc(GiaoDiem *listGiaoDiem, int k){
    double *listGoc = new double[k];
    for (int i = 0; i < k; i++)
    {
        listGoc[i] = Goc(listGiaoDiem[i]);
    }
    return listGoc;
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Nhap so luong duong thang: ";
    cin >> n;
    DuongThang *listLinear = new DuongThang[n];
    inputList(listLinear, n);
    GiaoDiem *LisGiaoDiem = new GiaoDiem[factorial(n)/(factorial(2)*factorial(n-2))];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            GiaoDiem g;
            giaoDiem(listLinear[i], listLinear[j], g);
            LisGiaoDiem[k] = g;
            k++;
            cout << "Giao diem cua duong thang thu " << i + 1 << " va duong thang thu " << j + 1 << " la: " << g.x << " va " << g.y << endl;
        }
    }
    double *listGoc = ListGoc(LisGiaoDiem, k);
    for (int i = 0; i < k; i++)
    {
        cout << "Goc giao diem thu " << i + 1 << " la: " << listGoc[i] << endl;
    }
    delete [] listGoc;
    delete [] listLinear;
    delete [] LisGiaoDiem;
    return 0;
}
