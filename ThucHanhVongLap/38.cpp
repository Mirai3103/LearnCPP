#include <iostream>
using namespace std;
int dequi(int n){
    return n==1?1:n*n+dequi(n-1);
}
int main()
{
    int n;
    cin >> n;
    int s= 0;
    for (int i = 1; i <= n; i++)
    {
        s+= i*i;
    }
    cout << "ket qua: "<< s;
    return 0;
}
