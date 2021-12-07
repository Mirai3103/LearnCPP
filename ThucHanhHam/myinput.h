
#include <iostream>
#include <io.h>
#include <fcntl.h>

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

void xuat()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << L"Tiếng Việt có dấu" << std::endl; 
}