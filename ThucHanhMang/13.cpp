#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n = 102;
    bool SanNt[102] ;
    
    fill_n(SanNt,102,true);
    for (int i = 2; i <n; i++)
    {
        if (SanNt[i])
        {
            for (int j = 2; j*i < n; j ++)
            {
                SanNt[j*i] = false;
            }
        }
    }
    for (int i = 2; i <n; i++)
    {
        if(SanNt[i]){
            cout << i <<" ";
        }
    }
    
    
    return 0;
}
