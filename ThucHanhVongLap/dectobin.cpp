#include <iostream>
using namespace std;
int main()
{
    int n, sodu;
    cin >> n;
    
    string bin= "";
    while (n!=0)
    {
        sodu = n%2;
        bin = to_string(sodu) + bin;
        n = n/2;
    }
    cout << "bin: " << bin;

    return 0;
}
