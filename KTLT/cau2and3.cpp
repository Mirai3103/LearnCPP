#include <iostream>
using namespace std;
#include <math.h>
int cau2dequi(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    int s = 0;
    int k = n;
    for (int i = 1; i <= n; i++)
    {
        k--;
        s = s + i * cau2dequi(k);
    }
    return s;
}

int DayConChanTangDaiNhat(int *arr, int length)
{
    int max = 0;
    int temp = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] % 2 == 0)
        {
            max++;
        }
        else
        {
            if (temp < max)
            {
                temp = max;
            }

            max = 0;
        }
    }
    return max > temp ? max : temp;
}
bool isPrimeNumber(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return n >= 2;
}
// int daonguoc(int x)
// {
//     if(x==0) return 0;
//     return daonguoc(x/10)*10 + x
// }
void cau3b()
{
    for (int i = 2; i < 1000; i++)
    {
        if (isPrimeNumber(i))
        {
            if (isPrimeNumber(daonguoc(i)))
            {
                cout << i << ", ";
            }
        }
    }
    cout << "...";
}
int cau2khongdequi(int n)
{
    int luu[100] = {};
    luu[0] = 1;
    luu[1] = 2;
    for (int i = 2; i <= n; i++)
    {
        int k = 0;
        for (int j = i; j >= 1; j--)
        {
            luu[i] = luu[i] + j * luu[k];
            k++;
        }
    }
    return luu[n];
}
int main()
{

    // cout << cau2dequi(5) << endl;
    cout << daonguoc(192);
    // int a[] = {2, 2, 2, 22, 2, 1, 2, 22, 62, 82};
    // cout << DayConChanTangDaiNhat(a, 10);

    return 0;
}
