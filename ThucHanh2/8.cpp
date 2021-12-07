#include <iostream>
using namespace std;
int main()
{
    // int input;
    // // string out = "";
    // cout << "Nhap so: ";
    // cin >> input;
    // out =  out + input.at(2) + input.at(1) + input.at(0);
    // cout << "so sau khi dao nguoc: " << out << endl;

    // cout << input % 10;
    // input = input / 10;
    // cout << input % 10;
    // input = input / 10;
    // cout << input % 10;

    // với mọi số
    int input;
    cout << "Nhap so: ";
    cin >> input;
    cout << "so sau khi dao nguoc: ";
    int ouput =0;
    // while (input != 0)
    // {
        ouput = ouput*10 + input % 10;
        input /= 10;
        ouput = ouput*10 + input % 10;
        input /= 10; 
        ouput = ouput*10 + input % 10;

    // }
    cout << ouput;
    return 0;
}
