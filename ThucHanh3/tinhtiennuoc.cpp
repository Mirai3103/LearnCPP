#include <iostream>
using namespace std;
int main()
{
    double sudung;
    cout << "Nhap luong nuoc su dung (m³):";
    cin >> sudung;
    double tongtien =0;
    if(sudung > 6){
        tongtien=tongtien + (sudung-6)* 10500;
        sudung = 6;
    }
    if(sudung > 4){
        tongtien=tongtien + (sudung-4)* 83000;
        sudung = 4;
    }
    tongtien= tongtien + (sudung)* 44000;
    cout << "so tien phai tra: "<< tongtien+tongtien*0.05+tongtien*0.1;
    return 0;
}
