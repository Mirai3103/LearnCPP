#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c;
    cout << "Nhap 3 so a, b ,c: \n";
    cin >> a >> b >> c;
    // if (a + b > c && b + c > a && c + a > b)
    // {
    //     cout << "la tam giac \n";
    //     if ((a == b) || (b == c) || (c == a))
    //     {
    //         cout << "day la tam giac can \n";
    //     }else{
    //         cout << "day khong la tam giac can \n";
    //     }
    // }
    // else
    // {
    //     cout << "khong phai la tam giac";
    // }
    int a, b, c;
    cin >> a >> b >> c;
    bool kttg = (a + b > c) && (a + c > b) && (b + c > a) ? true :false;
    bool tgCan = kttg? (a==b)|| (a==c)|| (b==c)? true: false:false;
    
           
}
