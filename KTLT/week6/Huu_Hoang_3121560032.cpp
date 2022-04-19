/*
 Ngo Huu Hoang
 3121560032
*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

void input(double **&arr, int &m, int &n);
void display(double **arr, int m, int n);
double sumOfNonNegativeNumbers(double **arr, int m, int n);
int *findSquareNumbers(double **arr, int m, int n, int &length);

int main()
{
    double **arr;
    int m, n;
    input(arr, m, n);
    display(arr, m, n);
    cout << "\nTong cac so khong am trong ma tran: " << sumOfNonNegativeNumbers(arr, m, n);
    int length = 0;
    int *SquareNumbers = findSquareNumbers(arr, m, n, length);
    if (length == 0)
    {
        cout << "\nKhong co so chinh phuong trong ma tran!";
    }
    else
    {
        cout << "\nCac so chinh phuong trong ma tran la: \n";
        for (int i = 0; i < length; i++)
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
            cout << setw(6) << setprecision(2) << fixed << arr[i][j];
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

int *findSquareNumbers(double **arr, int m, int n, int &length)
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
                squareNumbers[length++] = arr[i][j];
            }
        }
    }
    return squareNumbers;
}