#include <iostream>
using namespace std;
/*Nhập vào một ký tự. Hãy in thông báo cho biết ký tự đó là ký tự số, ký tự chữ cái,  
ký tự phép toán hay là ký tự dạng khác với các dạng trên
*/
int main()
{
    char c;
    cout << "nhap ki tu: ";
    cin >> c;
    if ('0' <= c && c <= '9')
    {
        cout << c << " la ki tu so";
    }
    else
    {
        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
        {
            cout << c << " la ki tu chu";
        }else{
            if(c=='+' ||c=='-' ||c=='*' ||c=='/' ){
                cout << c << " la ki tu toan hoc";
            }
            else{
                 cout << c << " la ki tu khac";
            }
        }
    }
    return 0;
}
