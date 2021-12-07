#include <iostream>
using namespace std;

string reverseStr(string str,int length){
    return length==0?str.at(0):str.at(length)+reverseStr(str,length-1)
}

int main()
{
    /* code */
    return 0;
}
