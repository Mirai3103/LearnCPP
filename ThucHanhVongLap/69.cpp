#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "nhap chieu cao: ";
    cin >> n;
    int max = n + n - 1;
    for (int i = 1; i <= n; i++)
    {
        int so_ngoi_sao_dong_nay = i + i - 1;
        int so_ki_tu_trong_1_ben = (max - so_ngoi_sao_dong_nay)/2;
        int vi_tri_sau =max - so_ki_tu_trong_1_ben;
        for (int j = 1; j <= max; j++)
        {
           if(j>so_ki_tu_trong_1_ben && j<= vi_tri_sau){
               cout << "*";
           }else{
               cout << " ";
           }
        }
        cout << endl;
    }

    return 0;
}