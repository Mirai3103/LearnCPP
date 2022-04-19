
#include <iostream>
using namespace std;
/*
X0 = X1 = 1;
Xn = X0*n + X1*(n-1) + X2*(n-2) + ... +  Xn-1
*/
int recur(int n)
{
    if(n == 0|| n == 1)
        return 1;
    int s = 0;
    for(int i = n-1; i >=0; i--)
        s += (n-i)*recur(i);
    return s;
}   

int usingStack(int n)
{
    if(n == 0|| n == 1)
        return 1;
    
    int s = 0;
    int stack[1000];
    int result[1000] = {};
    int topRS = -1;
    int top = -1;
    int temp = 0;
    stack[++top] = n;
    while(top != -1)
    {
        temp = stack[top--];
        if(temp == 0 || temp == 1)
        {
            result[++topRS] = temp;
            continue;
        }
    }

}

int main()
{
    int n;
    cin >> n;
    
    // int arr[100];
    //  arr[0] = 1;
    //  arr[1] = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     arr[i]=0;
    //     for (int j = 1; j <= i; j++)
    //     {
    //         arr[i] += j*arr[i-j];
    //     }
    // }
    printf("%d", usingStack(n));

    return 0;
}

