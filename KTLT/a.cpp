#include <iostream>
using namespace std;

int UCLN(int a,int b){
    if(a%b==0) return b;
    return UCLN(b, a%b);
}
int main(int argc, char const *argv[])
{
    cout << UCLN(1000,15);
    return 0;
}
