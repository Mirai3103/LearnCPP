#include <iostream>
using namespace std;
double dequi(int n){
    return n==1?1.0/2:1.0/(n*(n+1))+dequi(n-1);
}
int main()
{
    int n;
    cin >> n;
    double s= 0;
    for (int i = 1; i <= n; i++)
    {
        s =s+ 1.0/(i*(i+1));
    }
    cout << "\nket qua: "<<s;
    return 0;
}
