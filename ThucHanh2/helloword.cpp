#include <stdio.h>
#include <math.h>
bool isPrime(int n)
{
    if(n<2) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
void maxPrime(int arr[], int n)
{
    int maxPrime = -1;
    int index =-1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]> maxPrime)
        {
            if(isPrime(arr[i])){
                maxPrime = arr[i];
                index = i;
            }
        }
    }
    if(maxPrime!=-1){
        printf("\nvi tri la: %d gia tri: %d",++index,maxPrime);
    }
    else{
        printf("khong ton tai so nguyen to trong mang");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // tinh tong vi tri chan
    int s = 0;
    for (int i = 0; i < n; i += 2)
    {
        s = s + arr[i];
    }
    printf("\n%d", s);
    maxPrime(arr, n);
    return 0;
}
