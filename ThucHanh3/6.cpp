#include <iostream>
using namespace std;
/*6  Nhập vào giờ vào ca, giờ ra ca. Hãy tính và in ra tiền lương ngày 
cho công nhân, biết rằng tiền trả cho mỗi giờ trước 12 giờ trưa là 120000đ 
và mỗi giờ sau 12 giờ trưa là 155000đ. Giờ vào ca sớm nhất là 6 giờ sáng 
và giớ ra ca trễ nhất là 18 giờ. */
int main()

{
    double vaoca, raca;
    cout <<"nhap gio vao ca ";
    cin >> vaoca;
    cout <<"nhap gio ra ca ";
    cin >> raca;
    vaoca = vaoca<6?6:vaoca;
    raca = raca>18?18:raca;
    long tienluong;
    if(raca < vaoca ){
         tienluong = 0;
    }else{
        if(vaoca < 12 && raca < 12){
            tienluong = (raca-vaoca)*120000;
        }else{
             if(vaoca > 12){
                 tienluong = (raca-vaoca)*155000;
             }else{
                 
                 tienluong = (12-vaoca)*120000+(raca-12)*155000;
             }
        }
    }
    cout << "tien luong: "<< tienluong;
    return 0;
}
