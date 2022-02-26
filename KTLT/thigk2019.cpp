#include <iostream>
using namespace std;

int SumOfArray(int *arr, int length)
{
    if (length == 0)
        return 0;
    return arr[length - 1] + SumOfArray(arr, length - 1);
}
int FibonacciRecursion(int n)
{
    static int arr[100] = {1, 1};
    if (arr[n] == 0)
    {
        arr[n] = FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
    }
    return arr[n];
}
int FibonacciLoop(int n)
{
    int Xn, X0 = 1, X1 = 1;
    for (int i = 2; i <= n; i++)
    {
        Xn = X0 + X1;
        X0 = X1;
        X1 = Xn;
    }
    return Xn;
}
void ArrayInput(int *arr, int &n)
{
    cout << "Nhap chieu dai cua mang: ";
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> arr[i];
    }
}
void EvenAndOddNumberCount(int *arr, int n, int &EvenCout, int &OddCount)
{
    EvenCout = OddCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            EvenCout++;
        }
        else
        {
            OddCount++;
        }
    }
}
bool CheckIfArrSorted(int *arr, int n)
{
    if (n <= 1)
        return true;
    if (arr[n - 1] < arr[n - 2])
        return false;
    return CheckIfArrSorted(arr, n - 1);
}
void InterChangeSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void InputSquareMatrix(int ***A, int &n){
    cout << "Nhap so hang: ";
    cin >> n;
    *A = new int*[n];
    for (int i = 0; i < n; i++)
    {   
       (*A)[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            printf("Nhap phan tu thu %d, %d: ", i+1, j+1);
            cin >> (*A)[i][j];
        }
    } 
}
void Display(int **A, int n){
    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < n; j++)
        {
            printf("%3d", A[i][j]);
        }
        cout << endl;
    } 
}
int main()
{
    // int arr[] = {1, 2, 3, 2, 4};
    // cout << CheckIfArrSorted(arr, 4);
    int **A;
    int n;
    InputSquareMatrix(&A,n);
    Display(A,n);
    return 0;
}
