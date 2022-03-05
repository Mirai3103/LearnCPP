#include <iostream>
using namespace std;

int An(int n){
    if(n==1) return 1;
    int s = 0;
    for (int i = 1; i < n; i++)
    {
        s += An(n-i);
    }
    return n*s;
}



int main()
{
    int n;
    do
    {
        cin >> n;
    } while (n < 1);
    
    cout << An(n);
    return 0;
}
