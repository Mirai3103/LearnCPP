#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

bool isPrime(int n)
{

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return n > 1;
}

void readArrayFromFile(int **&arr, int &m, int &n)
{
    arr = new int *[m];
    fstream fin;
    fin.open("THI1.INP", ios::in);
    fin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            fin >> arr[i][j];
        }
    }
    fin.close();
}

void createArrayByNearestPrime(int **&arr, int &m, int &n)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isPrime(arr[i][j]))
            {
                count++;
            }
        }
    }
    int *arr2 = new int[count];
    int index = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isPrime(arr[i][j]))
            {
                arr2[index] = arr[i][j];
                index++;
            }
        }
    }
    delete[] arr;
    arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = arr2[i * n + j];
        }
    }
    delete[] arr2;
}
bool soDoiXung(int a)
{
    int sum = 0;
    int x = a;
    while (a > 0)
    {
        sum = sum * 10 + a % 10;
        a /= 10;
    }
    return sum == x;
}
int demSoDoiXung(int **arr, int m, int n)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (soDoiXung(arr[i][j]))
            {
                count++;
            }
        }
    }
    return count;
}
void showArray(int **arr, int m, int n)
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "\t";
        }

        cout << endl;
    }
}
int main()
{
    int **A;
    int **B;
    int m, n;
    readArrayFromFile(A, m, n);
    showArray(A, m, n);
    createArrayByNearestPrime(A, B, m, n);
    showArray(B, m, n);
    int count = demSoDoiXung(B, m, n);
    cout << count;
    return 0;
}
