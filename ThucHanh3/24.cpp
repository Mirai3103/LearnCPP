#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    const string username = "huuhoang";
    string password = "123456789";
    int sodu = 10000000;
    string inputusername, inputpassword;
    char tieptuc;
DangNhap:

    cout << "\n   Chuong trinh ATM\n\n";
    cout << "Moi ban dang nhap\n";
    cout << "Ten dang nhap: ";
    cin >> inputusername;
    cout << "Mat khau: ";
    cin >> inputpassword;
    if (inputusername == username && inputpassword == password)
    {
        TiepTucSuDung:
        cout << "\tCac chuc nang" << endl;
        cout << "1.Truy van tai khoan" << endl;
        cout << "2.Doi mat khau" << endl;
        cout << "3.Rut tien" << endl;
        int luachon;
        cout << "Nhap lua chon cua ban(1, 2, 3): ";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
            cout << "chuc nang truy van tai khoan" << endl;
            cout << "so tien co trong tai khoan ban la: " << sodu << "d\n";
            break;
        case 2:
            cout << "chuc nang doi mat khau" << endl;
            cout << "nhap mat khau hien tai: ";
            cin >> inputpassword;
            if (inputpassword == password)
            {
                cout << "nhap mat khau moi: ";
                cin >> password;
                system("clear");
                cout <<"doi mat khau thanh cong! moi ban dang nhap lai";
                goto DangNhap;
            }
            else
            {
                cout << "Nhap sai mat khau hien tai!";
            }
            break;
        case 3:
            cout << "chuc nang rut tien trong tai khoan" << endl;
            cout << "Nhap so tien can rut: " << endl;
            int sotienrut;
            cin >> sotienrut;
            if (sotienrut <= sodu)
            {
                sodu = sodu - sotienrut;
                cout << "rut thanh cong " << sotienrut << "đ\n";
                cout << "so du con lai trong tai khoan: " << sodu << endl;
            }
            else
            {
                cout << "ban khong co du so tien trong tai khoan de rut!\n";
            }
            break;

        default:
            cout << "lua chon khong hop le" << endl;
            break;
        }
        cout << "ban co muon su dung chuc nang khac? (Y/N)";
        cin >> tieptuc;
        if (tolower(tieptuc) == 'y')
        {
            goto TiepTucSuDung;
        }
        else
        {
            cout << "tam biet";
        }
    }
    else
    {
        cout << "sai ten dang nhap hoac mat khau!";
        cout << "\nban co muon dang nhap lai? (Y/N)";
        cin >> tieptuc;
        if (tolower(tieptuc) == 'y')
        {
            system("clear");
            goto DangNhap;
        }
        else
        {
            cout << "tam biet";
        }
    }

    return 0;
}
