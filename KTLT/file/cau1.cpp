#include <iostream>
#include <fstream>
using namespace std;

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

int countMax(int **arr, int m, int n, int &max)
{
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == max)
            {
                count++;
            }
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                count = 1;
            }
        }
    }
    return count;
}
void deleteMatrix(int **arr, int m)
{
    for (int i = 0; i < m; i++)
    {
        delete arr[m];
    }
    delete arr;
}
int main()
{
    int **arr;
    int m, n;
    readArrayFromFile(arr, m, n);
    int max = -1000;
    int count = countMax(arr, m, n, max);
    cout << "max: " << max;
    cout << " cout: " << count;
    deleteMatrix(arr, m);
    return 0;
}
