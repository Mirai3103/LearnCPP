#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c;
    cout << "Nhap 3 so a, b ,c: \n";
    cin >> a >> b >> c;
    if(a + b > c && b + c > a && c + a > b){
        cout << "la tam giac \n";
        if((a*a + b*b == c*c) ||(a*a + c*c == b*b) ||(b*b+ c*c == a*a)){
            cout << "day la tam giac vuong \n";
            if((a==b)||(b==c)||(c==a)){
                cout << "day la tam giac can \n";
            }
        }
    }else{
         cout << "khong phai la tam giac";
    }
    
    return 0;
}
