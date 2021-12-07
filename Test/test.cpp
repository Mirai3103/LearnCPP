#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    // dem so luong nguyen to <=n
    int dem = 0;
    for (int i = 2; i <= n; i++)
    {
        bool isprime = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime)
        {
            dem++;
        }
    }
    //tim so nguyen to thu n
    dem = 0;
    int k;
    int tontai = false;
    cout << "nhap vi tri so nguyen to can tim: ";
    cin >> k;
    for (int i = 2; i <= n; i++)
    {
        bool isprime = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime)
        {
            dem++;
            if (dem == k)
            {
                cout << "so nguyen to o vi tri " << k << " la: " << i;
                tontai = true;
            }
        }
    }
    if (!tontai)
    {
        cout << "khong the tim duoc\n";
    }
    // tim so nguyen to be hon n
    tontai = false;
    for (int i = n; i >= 2; i--)
    {
        bool isprime = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime)
        {
            cout << "\nso nguyen to be hon n dau tien la: " << i << endl;
            tontai = true;
            break;
        }
    }
    if (!tontai)
    {
        cout << "khong the tim duoc\n";
    }
    // in ra tat ca so nguen to
    if (n < 2)
    {
        cout << "khong ton tai day so nguyen to be hon n";
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            bool isprime = true;
            for (int j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    isprime = false;
                    break;
                }
            }
            if (isprime)
            {
                cout << i << ", ";
            }
        }
    }

    return 0;
}