#include <iostream>
using namespace std;
#include <stdio.h>
int main()
{
    int h, m, s;
    cout << "nhap gio, phut, giay: \n";
    cin >> h>> m>> s;
    bool isTime = false;
    if (s < 60){
        if (m < 60){
            if (h < 24){
                isTime = true;
            }
        }
    }

    if (isTime){
        // cout << "gio, phut giay nhap vao hop le: " << h << ":" << m << ":" << s << endl;
        //tang 1 giay
        printf("gio, phut giay nhap vao hop le: %02d:%02d:%02d\n",h,m,s);
        s = s + 1;
        if (s == 60){
            s = 0;
            m = m + 1;
            if (m == 60){
                m = 0;
                h = h + 1;
                if (h == 24){
                    h = 0;
                }
            }
        }
        // cout << "sau khi tang 1s: " << h << ":" << m << ":" << s;
        printf("sau khi tang 1s: %02d:%02d:%02d\n",h,m,s);
    }
    else
    {
        cout << "khong hop le \n";
    }
    return 0;
}
