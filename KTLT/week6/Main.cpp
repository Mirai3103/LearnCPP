#include <iostream>
#include <math.h>
using namespace std;

void input(double **&arr, int &m, int &n);
void display(double **arr, int m, int n);
double sumOfNonNegativeNumbers(double **arr, int m, int n);
int *findSquareNumbers(double **arr, int m, int n, int &l);

int main()
{
    double **arr;
    int m, n;
    input(arr, m, n);
    display(arr, m, n);
    cout << "\nTong cac so am trong ma tran: " << sumOfNonNegativeNumbers(arr, m, n);
    int l = 0;
    int *SquareNumbers = findSquareNumbers(arr, m, n, l);
    if (l == 0)
    {
        cout << "\nKhong co so chinh phuong trong ma tran";
    }
    else
    {
        cout << "\nCac so chinh phuong trong ma tran la: \n";
        for (int i = 0; i < l; i++)
        {
            cout << SquareNumbers[i] << ", ";
        }
    }
    return 0;
}

void input(double **&arr, int &m, int &n)
{
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    arr = new double *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new double[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Nhap phan tu [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void display(double **arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

double sumOfNonNegativeNumbers(double **arr, int m, int n)
{
    double sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] >= 0)
            {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

int *findSquareNumbers(double **arr, int m, int n, int &l)
{
    int *squareNumbers = new int[m * n];
    int temp = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp = (int)sqrt(arr[i][j]);
            if (temp * temp == arr[i][j])
            {
                squareNumbers[l++] = arr[i][j];
            }
        }
    }
    return squareNumbers;
}