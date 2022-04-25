
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    int value;
} Element;

// function prototype
void inputSparseMatrix(Element SM[], int m, int n);
void printMatrix(Element SM[]);
void printRawSparseMatrix(Element SM[]);
void transpose(Element A[], Element B[]);

// main function
int main()
{
    printf("Enter the matrix elements of size 3 by 3\n");
    Element SM[10];
    inputSparseMatrix(SM, 3, 3);
    printf("Given matrix is\n");
    printMatrix(SM);
    printf("Sparse Matrix is\n");
    printRawSparseMatrix(SM);
    Element SMT[9];
    transpose(SM, SMT);
    printf("Transpose is\n");
    printRawSparseMatrix(SMT);
    return 0;
}

// function definition
void inputSparseMatrix(Element SM[], int m, int n)
{
    int temp;
    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &temp);
            if (temp != 0)
            {
                SM[k].row = i;
                SM[k].col = j;
                SM[k].value = temp;
                k++;
            }
        }
    }
    SM[0].row = m;
    SM[0].col = n;
    SM[0].value = k - 1;
}

void printMatrix(Element SM[])
{
    int i = 1;

    for (int j = 0; j < SM[0].row; j++)
    {
        for (int k = 0; k < SM[0].col; k++)
        {
            if (SM[i].row == j && SM[i].col == k && i <= SM[0].value)
            {
                printf("%d ", SM[i].value);
                i++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void printRawSparseMatrix(Element SM[])
{
    for (int i = 0; i <= SM[0].value; i++)
    {
        printf("[%d] %d %d %d\n", i, SM[i].row, SM[i].col, SM[i].value);
    }
}

void transpose(Element A[], Element B[])
{
    B[0].row = A[0].col;
    B[0].col = A[0].row;
    B[0].value = A[0].value;
    int i = 1;
    int j = 1;
    while (i <= A[0].value)
    {
        B[j].row = A[i].col;
        B[j].col = A[i].row;
        B[j].value = A[i].value;
        i++;
        j++;
    }
}