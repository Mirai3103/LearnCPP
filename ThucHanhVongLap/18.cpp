#include <iostream>
using namespace std;

int bai18(int n){
    int donvi;
    int m =0;
    while (n>0)
    {
        donvi = n%10;
        n =n/10;
        if(donvi!=5 && donvi!=0) m = m*10+donvi;

    }
    return m;

}
int main()
{
    int n;
    cin >> n;  
    cout <<"so can tao la: "<<bai18(n);
    return 0;
}
