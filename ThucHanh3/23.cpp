#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int luachon;
    char tieptuc;
tieptuc:
    cout << "Cac lua chon: " << endl;
    cout << "1-Ha Noi" << endl;
    cout << "2-Da Nang " << endl;
    cout << "3-Buon Ma Thuot " << endl;
    cout << "4-Vinh" << endl;
    cout << "5-TP Ho Chi Minh" << endl;
    cout << "Nhap lua chon cua ban: ";

    cin >> luachon;
    switch (luachon)
    {
    case 1:
        cout << "XIN MOI DEN PHONG SO 1, Lau 1 \n";
        break;
    case 2:
        cout << "XIN MOI DEN PHONG SO 2, Lau 2 \n";
        break;
    case 3:
        cout << "XIN MOI DEN PHONG SO 3, Lau 3 \n";
        break;
    case 4:
        cout << "XIN MOI DEN PHONG SO 4, Lau 4 \n";
        break;
    case 5:
        cout << "XIN MOI DEN PHONG SO 5, Lau 5 \n";
        break;

    default:
        cout << "lua chon khong hop le\n";
        break;
    }
    cout << "ban co muon tiep tuc (Y/N): ";
    cin >> tieptuc;
    if(tolower(tieptuc)=='y'){
        goto tieptuc;
    }else{
        cout << "tam biet";
    }

    return 0;
}
