#include <iostream>
#include <cstring>
using namespace std;
void tts(string s);



string sangchu(int n)
{
    switch (n)
    {
    case 0:
        return "khong ";
    case 1:
        return "mot ";
    case 2:
        return "hai ";
    case 3:
        return "ba ";
    case 4:
        return "bon ";
    case 5:
        return "nam ";
    case 6:
        return "sau ";
    case 7:
        return "bay ";
    case 8:
        return "tam ";
    case 9:
        return "chin ";
    }
    return "khong hop le";
}
void docso(int n)
{
    string chu = "";
    while (n != 0)
    {
        chu = sangchu(n % 10) + chu;
        n = n / 10;
    }
    cout << chu;
    tts(chu);
    
    
}
void scan(int &n){
    do
    {
        cout << "Nhap n: ";
        cin >> n;
    } while (n<0);
    
}
int main()
{
    int n;
    scan(n);
    docso(n);
    return 0;
}













void tts(string s){
    s= "python speak.py "+s;
    system(s.c_str());
}
