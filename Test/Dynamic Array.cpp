#include <iostream>
using namespace std;

void cc(int *arr){  // truyền vào hàm là con trỏ
    cout << *(arr+1) << endl;
}
int main()
{
     // tạo mảng động với con trỏ
    int n;
    cin >> n;
    int *array = new int[n];  // cấp phát 1 mảng ô nhở kiểu int
    // nhập phần xuất của mảng động
    for (int i = 0; i < n; i++)
    {
        cin >> *(array+i);   
        cout << *(array+i) << endl;
    }
    
    
    cc(array);
    delete[] array;
    return 0;
}
