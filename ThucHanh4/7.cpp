#include <iostream>
// tim so lon nhat trong 3 so
using namespace std;

int main()
{
    int a, b, c;
    cout << "Nhap 3 so a, b ,c: \n";
    cin >> a >> b >> c;
    //  tim gia tri lon nhat
    // int max = (a > b && a > c) ? a : (b > a && b > c) ? b : c;
    // cout << "gia tri lon nhat la: " << max << endl;
    // so lon nhat
    if (a > b && a > c)
    {
        cout << "a la so lon nhat." << endl;
    }
    else if (b > a && b > c)
    {
        cout << "b la so lon nhat." << endl;
    }
    else
    {
        cout << "c la so lon nhat." << endl;
    }
    return 0;
}
