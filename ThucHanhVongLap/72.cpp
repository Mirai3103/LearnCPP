#include <iostream>
using namespace std;

int main()
{
    int d,r;
    cout << "nhap chieu dai: ";
    cin >> d;
    cout << "nhap chieu rong: ";
    cin >> r;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            if(i==1 || i == d ){
                cout << "*";
            }else{
                if(j == 1 || j == r)cout << "*";
                else cout << " ";
                
            }
        }
        cout << endl;
    }
    

    return 0;
}