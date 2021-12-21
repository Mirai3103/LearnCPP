#include <iostream>
using namespace std;
const int Max = 100;
void xuatmang2d(int a[100][100], int dong, int cot){
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
           cout << a[i][j]<<endl;
        }
        cout << endl;
    }
    
}

void nhapmang2d(int a[100][100], int &dong, int &cot){
    cout << "nhap so dong: ";
    cin >> dong;
    cout << "nhap so cot: ";
    cin >> cot;

    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            printf("nhap a[%d][%d]: ", i,j);
            cin >> a[i][j];
        }
        
    }
    
}
void chuyenvi(int a[100][100], int dong, int cot, int t[100][100]){
    for (int i = 0; i < cot; i++)
    {
        for (int j = 0; j < dong; j++)
        {
            t[i][j] = a[j][i];
        }
        
    }
    
}
int main()
{
    
    return 0;
}
