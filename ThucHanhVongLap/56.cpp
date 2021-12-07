#include <iostream>
using namespace std;
int main()
{

    int n = 2;
    int s =0;
    for (int i = 1; i <= n; i++)
    {
        s=s+i*2;
    }
    double vephai = n*(n+1)*(2*n+1)*1.0/6; 

    return 0;
}
