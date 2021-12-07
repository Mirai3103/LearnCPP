#include <iostream>
using namespace std;

void xuatmang2chieu(int *a[],int n, int m) //Array containing pointers
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "; ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];              // mang gom cac so nguyen
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ";";
    }
    n =3;
    int *array[n]; // mang gom cac con tro kieu int
    // array[1] = &n;// hop le
    // array[1] = n;// khong hop le
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[n];
    } // tạo mảng con  trỏ 2 chiều
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> array[i][j];
        }
        
    }
    xuatmang2chieu(array, n, n);
    



    // giai phong bo nho
    for (int i = 0; i < 10; i++)
    {
        delete[] array[i];
    }
    delete[] arr;
    return 0;
}
