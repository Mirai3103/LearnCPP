#include <iostream>
using namespace std;
#include <math.h>
const int ROW = 8, COL = 8;

struct Cell
{
    int row, col;
};
Cell listStep[64];
int count = 0;
bool isNotDuplicateStep(int nextRow, int nextCol)
{
    for (int i = 0; i < count; i++)
    {
        if (listStep[i].col == nextCol && listStep[i].row == nextRow)
        {
            return false;
        }
    }
    return true;
}
bool isInvalidNextStep(int currentRow, int currentCol, int nextRow, int nextCol)
{
    return (abs(currentRow - nextRow) + abs(currentCol - nextCol)) == 3 && currentRow != nextRow && currentCol != nextCol;
}
void show()
{
    cout << endl;
    for (int i = 0; i < 64; i++)
    {
        printf("Step %d: %d, %d \n", i + 1, listStep[i].row, listStep[i].col);
    }
    cout << "=================";
}
void TRY(bool isFirst = true)
{
    if (count == 64)
    {
        show();
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (isFirst)
            {
                listStep[count].row = i;
                listStep[count].col = j;
                count++;
                TRY(false);
                count--;
            }
            else
            {
                if (isInvalidNextStep(listStep[count - 1].row, listStep[count - 1].col, i, j))
                {
                    if (isNotDuplicateStep(i, j))
                    {
                        listStep[count].row = i;
                        listStep[count].col = j;
                        count++;
                        TRY(false);
                        count--;
                    }
                }
            }
        }
    }
}
int main()
{
    int arr[8][8] = {};
    TRY();
    return 0;
}
