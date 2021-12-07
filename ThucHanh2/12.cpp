#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(1251); 
    int year;
    cout << " nhap nam: ";
    cin >> year;
    if(year % 4 == 0){
        cout << year <<"la nam nhuan";
    }else if(year % 400 == 0){
        cout << year <<"la nam nhuan";
    }else{
        cout << year <<"khong phai la nam nhuan";
    }
    return 0;
}
