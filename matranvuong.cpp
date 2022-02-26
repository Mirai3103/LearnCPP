#include <iostream>
using namespace std;

void Display(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", A[i][j]);
        }
        cout << endl;
    }
}
int **InputSquareMatrix(int &n)
{
    cout << "Nhap so hang: ";
    cin >> n;
    int **A = new int *[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            printf("Nhap phan tu thu %d, %d: ", i + 1, j + 1);
            cin >> A[i][j];
        }
    }
    return A;
}
int SumMainDiagonal(int **A, int n)
{
    if (n == 0)
        return 0;
    return A[n - 1][n - 1] + SumMainDiagonal(A, n - 1);
}
int SumSubDiagonal(int **A, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i][n - i - 1];
    }
    return sum;
}
void ShowLowerTriangularMatrix(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i>j){
                printf("%3d", A[i][j]);
            }
        }
        cout << endl;
    }
}
void ShowLowerTriangularMatrixOfSubDiagonal(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i+j>=n){
                printf("%3d", A[i][j]);
            }
            else
            {
                cout <<"   ";
            }
            
        }
        cout << endl;
    }
}
int main()
{
    // int arr[] = {1, 2, 3, 2, 4};
    // cout << CheckIfArrSorted(arr, 4);
    int n;
    int **A = InputSquareMatrix(n);
    Display(A, n);
    cout << endl;
    ShowLowerTriangularMatrixOfSubDiagonal(A,n);
    return 0;
}
