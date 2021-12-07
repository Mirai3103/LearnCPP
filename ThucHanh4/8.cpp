#include <iostream>
using namespace std;
int main()
{
    string input;
    string out = "";
    cout << "Nhap so: ";
    cin >> input;
    out =  out + input.at(2) + input.at(1) + input.at(0);
    cout << "so sau khi dao nguoc: " << out << endl;

    // voi moi so
    // int input;
    // cout << "Nhap so: ";
    // cin >> input;
    // cout << "so sau khi dao nguoc: ";
    // while (input != 0)
    // {
    //     cout << input % 10;
    //     input /= 10;
    // }

    return 0;
}
