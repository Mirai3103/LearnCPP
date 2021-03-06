#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;

struct DuongThang
{
    double a;
    double b;
    double c;
};
struct GiaoDiem
{
    double x;
    double y;
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
void giaoDiem(DuongThang &l1, DuongThang &l2, GiaoDiem &g)
{
    g.linear1 = &l1;
    g.linear2 = &l2;
    g.x = (l1.c*l2.b-l2.c*l1.b)*1.0/(l1.a*l2.b-l2.a*l1.b);
    g.y = (l1.a*g.x+l1.c)*1.0/-l1.b;
}
int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
double rad2deg(double rad)
{
    return rad * 180 / M_PI;
}
double Goc(GiaoDiem g){
    double cos = (g.linear1->a * g.linear2->a + g.linear1->b * g.linear2->b)*1.0 / (sqrt(g.linear1->a * g.linear1->a + g.linear1->b * g.linear1->b) * sqrt(g.linear2->a * g.linear2->a + g.linear2->b * g.linear2->b));
    return rad2deg(acos(cos));
}
double *ListGoc(GiaoDiem *listGiaoDiem, int k){
    double *listGoc = new double[k];
    for (int i = 0; i < k; i++)
    {
        listGoc[i] = Goc(listGiaoDiem[i]);
    }
    return listGoc;
}

int main()
{
    int n;
    cout << "Nhap so luong duong thang: ";
    cin >> n;
    DuongThang *listLinear = new DuongThang[n];
    inputList(listLinear, n);
    for (int i = 0; i < n; i++)
    {
        printf("%.2fx + %.2fy + %.2f = 0\n", listLinear[i].a, listLinear[i].b, listLinear[i].c);
    }
    
    GiaoDiem *LisGiaoDiem = new GiaoDiem[factorial(n)/(factorial(2)*factorial(n-2))];
    cout << factorial(n)/(factorial(2)*factorial(n-2)) << endl;
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
        cout << "Goc giao diem thu " << i + 1 << " la: " <<setprecision(n)<<fixed << listGoc[i] << endl;
    }
    delete [] listGoc;
    delete [] listLinear;
    delete [] LisGiaoDiem;
    return 0;
}
