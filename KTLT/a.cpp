#include <iostream>
using namespace std;


// tìm chữ số có giá trị lớn nhất trong 1 số nguyên sử dụng đệ qui
int MAX(int n, int max = 0){
    if(n == 0) return max;
    if(n%10>max) max = n%10;
    return MAX(n/10, max);
}
int main()
{
    cout << MAX(8234);
    return 0;
}
