#include <iostream>
using namespace std;


int Sum1ToN(int n){
    if(n==0) return 0;
    return n+Sum1ToN(n-1);
}
double S(int n){
    if(n==1) return 1.0;
    return 1.0/Sum1ToN(n)+S(n-1);
}

int main()
{
 
}