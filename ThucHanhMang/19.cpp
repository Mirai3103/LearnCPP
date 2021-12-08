#include <iostream>
using namespace std;

void nhapmang(int arr[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap Phan tu thu " << (i + 1) << ":";
        cin >> arr[i];
    }
}
void solve(int arr[], int n)
{
    bool isCheck[100] = {};
    int dem;
    for (int i = 0; i < n; i++)
    {
        if (!isCheck[i])
        {
            dem = 1;
            for (int j = i + 1; j < n ; j++)
            {
                if (arr[i] == arr[j])
                {
                    dem++;
                    isCheck[j] = true;
                }
            }
            printf("%d xuat hien %d lan \n", arr[i], dem);
        }
        
    }
}

int main()
{
    int arr[100];

    int n;
    nhapmang(arr, n);
    solve(arr, n);
    return 0;
}
