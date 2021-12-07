#include <iostream>
using namespace std;
int main()
{
    int bin;
    cin >> bin;
    int dec =0;
    int donvi;
    int i = 1;
    cout << "\nnhi phan: "<<bin;
    while (bin != 0)
    {
        donvi = bin % 10;
        dec = dec + i * donvi;
        bin = bin / 10;
        i = i * 2;
    }
    cout <<"\nthap phan: "<< dec;  
    int sodu;
    string oct= "";
    while (dec!=0)
    {
        sodu = dec%8;
        oct = to_string(sodu) + oct;
        dec = dec/8;
    }
    cout << "\nbat phan: " << oct;

    return 0;
}
