#include <iostream>
using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int donvi;
//     bool sotien = true;

//    do
//    {
//        donvi = n%10;
//        n = n/10;
//        if(donvi<n%10){
//            sotien = false;
//        }
//    } while (n!=0 && sotien);

//     if(sotien){
//         cout <<"n la so tien";
//     }else{
//         cout <<"n khong phai la so tien";
//     }

//     return 0;
// }
int main()
{
    int n, sotien, dv, chuc; // so tien bang khong ==> n khong la so tien; nguoc lai cout<<"nhap vao so n can kiem tra: "; cin>>n; sotien=1;// danh dau trang thai n la so tien
    do
    {
        dv = n % 10;
        n = n / 10;
        chuc = n % 10;
        if ((dv < chuc))
        {
            sotien = 0;
        }
    } while (sotien == 1 && (n > 10));
    if (sotien == 1)
    {
        cout << "n la so tien";
    }
    else
    {
        cout << "n khong la so tien";
    }
    return 0;
}
