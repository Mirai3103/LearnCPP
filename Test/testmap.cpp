#include <iostream>
// #include <map>
using namespace std;


// map<int, int> phantichthanhthuasonguyento(int n){
//     map<int, int> thuaso ;
//     int i = 2;
//     while (n!=1)
//     {   
//         if(n % i == 0) thuaso[i]=0;
//         while (n % i == 0)
//         {
//             n = n / i;
//             thuaso[i]++;
//         }
//         i++;
//     }
//     return thuaso;
// }

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
        str1 = str1 + "+";
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
    cout << "cach 2: " << dang2(n)<< endl;
    // map<int, int> thuaso = phantichthanhthuasonguyento(n);
    // for (const auto& so : thuaso) {
    // cout << so.first << "^" << so.second <<endl;
    // }
    return 0;
}

