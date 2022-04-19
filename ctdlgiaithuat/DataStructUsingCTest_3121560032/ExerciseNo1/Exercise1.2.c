/*
Write a Program for addition of two matrices using two dimensional array 
*/

#include <stdio.h>
#define ROW 100

// function prototype
void inputMatrix(int arr[][ROW], int m, int n);
void displayMatrix(int arr[][ROW], int m, int n);
void addMatrix(int arr1[][ROW], int arr2[][ROW], int resultArray[][ROW], int m, int n);


// main function
int main()
{
    
    int arr1[ROW][ROW], arr2[ROW][ROW], resultArray[ROW][ROW], m, n;

    // input the size of matrix
    printf("Enter the number of rows of matrix : ");
    scanf("%d", &m);
    printf("Enter the number of columns of matrix : ");
    scanf("%d", &n);

    // input the elements of first matrix
    printf("Enter the elements of first matrix : \n");
    inputMatrix(arr1, m, n);
    // input the elements of second matrix
    printf("Enter the elements of second matrix : \n");
    inputMatrix(arr2, m, n);
    
    // display the elements of first matrix
    printf("\nFirst matrix is : \n");
    displayMatrix(arr1, m, n);

    // display the elements of second matrix
    printf("\nSecond matrix is : \n");
    displayMatrix(arr2, m, n);

    // add the elements of first matrix and second matrix then display the result
    printf("\nSum of two matrix is : \n");
    addMatrix(arr1, arr2, resultArray, m, n);
    displayMatrix(resultArray, m, n);

    
    return 0;
}

// function definition
void inputMatrix(int arr[][ROW], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter element %d, %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}

void displayMatrix(int arr[][ROW], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d, ", arr[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int arr1[][ROW], int arr2[][ROW], int resultArray[][ROW], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            resultArray[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}
