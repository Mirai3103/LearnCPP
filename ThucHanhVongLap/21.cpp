#include <iostream>
#include <string>
using namespace std;

string dang1(int n){
    string str1 = "";
    int i = 2;
    while (n!=1)
    {  
        while (n % i == 0)
        {
            n = n / i;
            str1 = str1 +  to_string(i)+"*";
        }
        str1[str1.length()-1] = '\0';
        str1 = str1 + "*";
        i++;
    }
    str1[str1.length()-1] = '\0';
    return str1;
}

string dang2(int n){
    int luythua;
    string str2 = "";
    int i = 2;
    while (n!=1)
    {  
        luythua = 0;
        while (n % i == 0)
        {
            luythua++;
            n = n / i;
          
        }
         if (luythua != 0)
            str2 = str2 + to_string(i) + "^" + to_string(luythua) + "+";
        
        i++;
    }
    str2[str2.length()-1] = '\0';
    return str2;
}

int main()
{
    int n;
    cin >> n;
    cout << "cach 1: " << dang1(n) << endl;
    cout << "cach 2: " << dang2(n);
    return 0;
}
