#include <iostream>
using namespace std;
const int ROW = 8, COL = 8;
bool checkRow(int arr[ROW][COL], int rowindex)
{
    for (int i = 0; i < COL; i++)
    {
        if (arr[rowindex][i] == 1)
            return false;
    }
    return true;
}
bool checkCol(int arr[ROW][COL], int colIndex)
{
    for (int i = 0; i < ROW; i++)
    {
        if (arr[i][colIndex] == 1)
            return false;
    }
    return true;
}
bool checkDiagonalLTR(int arr[ROW][COL], int rowIndex, int colIndex)
{
    const int temp = rowIndex - colIndex;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if ((i - j) == temp)
            {
                if (arr[i][j] == 1)
                    return false;
            }
        }
    }
    return true;
}
bool checkDiagonalRTL(int arr[ROW][COL], int rowIndex, int colIndex)
{
    const int temp = rowIndex + colIndex;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if ((i + j) == temp)
            {
                if (arr[i][j] == 1)
                    return false;
            }
        }
    }
    return true;
}
bool check(int arr[ROW][COL], int rowIndex, int colIndex)
{
    return checkCol(arr, colIndex) && checkRow(arr, rowIndex) && checkDiagonalLTR(arr, rowIndex, colIndex) && checkDiagonalRTL(arr, rowIndex, colIndex);
}

void show(int arr[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "===============\n";
}

void TRY(int arr[ROW][COL], int count)
{
    if (count > 8)
    {
        show(arr);
    }
    else
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (arr[i][j] == 0)
                {
                    if (check(arr, i, j))
                    {
                        arr[i][j] = 1;
                        TRY(arr, count + 1);
                        arr[i][j] = 0;
                    }
                }
            }
        }
    }
}

int main()
{
    int arr[8][8] = {};
    TRY(arr, 1);
    return 0;
}
