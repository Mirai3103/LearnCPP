#include <iostream>
using namespace std;

int FibonacciRecursion(int n)
{
    static int arr[100] = {1, 1};
    if(n>100) return FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
    if (arr[n] == 0)
    {
        arr[n] = FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
    }
    return arr[n];
}

int DecToBin(int n){
    if (n==0) return 0;
    return n%2+10*DecToBin(n/2);
}
int DecToBinRecursion(int n){
    if (n==0) return 0;
    return n%10+10*DecToBinRecursion(n/10);
}
int Yn(int n);
int Xn(int n);
void show(int *arr, int n){
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    
}
void Backing(int i, int n){
    static int x[100];
    for (int j = 0; j <2; j++)
    {
        x[i] = j;
        if(i > n){
            show(x, n);
            return;
        }else{
            Backing(i+1,n);
        }
    }
    
}

int main()
{
    Backing(1,3);
    
    return 0;
}



int Xn(int n){
    if(n == 0) return 1;
    return Xn(n-1)+Yn(n-1);
}
int Yn(int n){
    if(n == 0) return 1;
    return 3*Xn(n-1)+2*Yn(n-1);
}