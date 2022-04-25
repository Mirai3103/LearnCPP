#include <iostream>
using namespace std;

float **createSquareMatrix(int n)
{
    float **matrix = new float *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new float[n];
    }
    return matrix;
}
void freeMatrix(float **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
void inputSquareMatrix(float **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Nhap A[][]: ", i, j);
            cin >> arr[i][j];
        }
    }
}
void showSquareMatrix(float **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f\t", arr[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}
float tongCacPhanTuDuongCheoChinh(float **arr, int n)
{
    if (n == 0)
        return 0;
    return arr[n - 1][n - 1] + tongCacPhanTuDuongCheoChinh(arr, n - 1);
}
float tongCacPhanTuDuongCheoPhu(float **arr, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i][n - 1 - i];
    }
    return sum;
}

float tongCacPhanTuTamGiacDuoiDuongCheoPhu(float **arr, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1 - i; j < n; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}
int main()
{
    int n;
    do
    {
        cout << "nhap kich co ma tran vuong >0: ";
        cin >> n;
    } while (n <= 0);
    float **matrix = createSquareMatrix(n);
    inputSquareMatrix(matrix, n);
    cout << "Ma tran vuong da nhap la: \n";
    showSquareMatrix(matrix, n);
    cout << "Tong cac phan tu tren duong cheo chinh la: " << tongCacPhanTuDuongCheoChinh(matrix, n) << endl;
    cout << "Tong cac phan tu tren duong cheo phu la: " << tongCacPhanTuDuongCheoPhu(matrix, n) << endl;
    cout << "Tong cac phan tu thuoc tam giac duoi la: " << tongCacPhanTuTamGiacDuoiDuongCheoPhu(matrix, n) << endl;
    freeMatrix(matrix, n);
    return 0;
}
