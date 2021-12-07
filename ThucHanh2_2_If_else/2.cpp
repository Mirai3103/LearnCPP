#include <iostream>
using namespace std;

int main()
{
    int chieucao, vongnguc, cannang;
    cout << "nhap chieu cao: ";
    cin >> chieucao;
    cout << "nhap vong nguc: ";
    cin >> vongnguc;
    cout << "nhap can nang: ";
    cin >> cannang;
    int Pignet = chieucao - (vongnguc +cannang);
    return 0;
}
