/*Câu 3: Tìm các dãy nhị phân có độ dài n, với n là số nguyên dương.
 Ví dụ n=3 thì có các kết quả: 000, 001, 010, 011, 100, 101, 110, 111.*/
#include <iostream>
using namespace std;
int arr[100];
void inChuoiNhiPhan(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
void timChuoiNhiPhan(int n, int index = 0)
{
    if (index == n)
    {
        inChuoiNhiPhan(n);
    }
    else
    {
        for (int i = 0; i <= 1; i++)
        {
            arr[index] = i;
            timChuoiNhiPhan(n, index + 1);
        }
    }
}

int main()

{
    int n;
    cin >> n;
    timChuoiNhiPhan(n); // = 2^4 = 16
    return 0;
}
