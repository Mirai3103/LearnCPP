
#include <iostream>
using namespace std;

void nhap(int &n, bool (*dieukien)(int))
{
    do
    {
        cout << "nhap: ";
        cin >> n;
    } while (!dieukien(n));
}
bool sotunhien(int n){
    return n >=0;
}

