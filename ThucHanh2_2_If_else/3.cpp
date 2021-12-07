#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin >> a,b;
    if(a==0){
        if(b==0) cout <<"moi nguoi 2 nam tu";
        else  cout << "A 4 nam tu và B tha bong";
    }else
    {
        if(b==0) cout << "B 4 nam tu và A tha bong";
        else cout << "moi nguoi 3 nam tu";
    }
    
    return 0;
}
