#include <iostream>
using namespace std;

int Xn(int n);
int Yn(int n);


int main()
{
    int n;
    do
    {
        cin >> n;
    } while (n<0);
    cout << Xn(n)<< "   "<<Yn(n);
    return 0;
}



int Xn(int n){
    if(n==0) return 1;
    return Xn(n-1)+Yn(n-1);
}
int Yn(int n){
    if(n==0) return 1;
    return 3*Xn(n-1)+2*Yn(n-1);
}
