#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return x >= 2;
}
int sodao(int n)
{
    int ketqua = 0;
    while (n > 0)
    {
        ketqua = ketqua * 10 + n % 10;
        n = n / 10;
    }
    return ketqua;
}
int nextPrime(int n)
{
    int a = n + 1;
    while (true)
    {
        if (isPrime(a))
            return a;
        a++;
    }
    return 0;
}
int twomun(int n){
    if(n==1) return 2;
    return 2*twomun(n-1);
}
int main()
{
    int n;
    cout << "a) nhap n: ";
    cin >> n;
    cout << "so nguyen to nho hon " << n << endl;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            cout << i << "; ";
    }
    cout << "\nb) nhap n: ";
    cin >> n;
    cout << endl
         << n << " so nguyen dau tien:  " << endl;
    int i = 0;
    int sont = 2;
    while (i <= n)
    {
        if (isPrime(sont))
        {
            cout << sont << "; ";
            i++;
        }
        sont++;
    }
    cout << "\nc) nhap n: ";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        if (isPrime(i))
        {
            if (isPrime((sodao(i))))
            {
                cout << i << "; ";
            }
        }
    }
    cout << "\nd) nhap n: ";
    cin >> n;
    int truoc = 2;
    int hientai = 3;
    int tieptheo = nextPrime(hientai);
    while (tieptheo < n)
    {
        
        if (hientai == (truoc + tieptheo) * 1.0 / 2)
        {
            cout << hientai << "; ";
        }
        truoc = hientai;
        hientai = tieptheo;
        tieptheo = nextPrime(hientai);
    }
    cout << "\ne) nhap n: ";
    cin >> n;
    int k = 2;
    sont =0;
    do
    {
        if(isPrime(k)){
            sont = twomun(k)-1;
            if(isPrime(sont))cout << "2^"<<k<<": "<<sont << endl;
        }
        k++;
    } while (sont < n );
    
    return 0;
}
