#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sodao=0;
    while (n!=0)
    {
        sodao = sodao*10 + n%10;
        n /=10; 
    }
    cout <<"so dao la: "<<sodao;
    

    return 0;
}
