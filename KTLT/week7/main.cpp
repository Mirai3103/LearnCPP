#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int wordCount(char *s){
    int count = 0;
    while(*s ==' '){
        s++;
    }
    if(*s=='\0'){
        return 0;
    }
    while(*s!='\0'){
        if(*s==' ' &&*(s+1)!=' ' && *(s+1)!='\0'){
            count++;
        }
        s++;
    }
    return ++count;

}

int maxLengthWord(char *s){
    if(*s == ' '){
        return maxLengthWord(++s);
    }
    if(*s == '\0'){
        return     0;
    }
    int length = 0;
    while(*s != ' ' && *s!=0 ){
        length++;
        s++;
    }
    return max(length, maxLengthWord(s));
}

char * subString(char *s, int pos, int n){
    int i = 0;
    int j = 0;
    char *rs = new char[strlen(s)] ;
    while(i<pos && s[i]!='\0')
    {
        i++;
    }
    if(s[i]=='\0'){
        return rs;
    }
    for(; j<n ;j++, i++){
        if(s[j]=='\0') break;
        rs[j] = s[i];
         
    }
    rs[j] ='\0';
    return rs;
}
int main()
{
    char s[]= "ngohhua    dasdadsasd hoang    ";
    cout << wordCount(s);
    cout << maxLengthWord(s);
    cout << subString(s,1,3);
    return 0;
}
