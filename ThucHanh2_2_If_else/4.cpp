#include <iostream>
using namespace std;

int main()
{
    char luachon;
    a:
    cout << "Ban muon nhap do F hay do C: ";
    cin >> luachon;
    double t;
    
    cout << "Nhap nhiet do: ";
    cin >>t;
    if (toupper(luachon) == 'C')
    {
        cout << t <<"C = "<<(9*1.0*t/5)+32 <<"F";
    }else{
        if(toupper(luachon) == 'F'){
            cout << t <<"F = "<< 5*1.0*(t-32)/9<<"C";
        }else{
            cout << "lua chon khong hop le";
            goto a;
        }
    }
    return 0;
}
