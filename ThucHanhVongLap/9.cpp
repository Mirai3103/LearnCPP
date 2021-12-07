#include <iostream>
using namespace std;


int demsochuso(int n)
{
    int sochuso = 0;
    int donvi = 0;
    while (n != 0)
    {
        donvi = n % 10;
        n = n / 10;
        sochuso++;
    }
    return sochuso;
}

int soOViTriI(int n, int i, int sochuso)
{
    int donvi = 0;
    i = sochuso - i + 1;
    while (i != 0)
    {
        donvi = n % 10;
        n = n / 10;
        i--;
    }
    return donvi;
}
int main()
{
    int n, i;
    cout << "nhap n:";
    cin >> n;
    cout << "vi tri muon tim:";
    cin >> i;

    int sochuso = demsochuso(n);

    if (i > sochuso || i <=0)
    {
        cout << "khong the tim";
    }
    else
    {
        int soovitrii = soOViTriI(n, i, sochuso);
        cout << "so o vi tri " << i << " la: " << soovitrii;
    }

    return 0;
}
