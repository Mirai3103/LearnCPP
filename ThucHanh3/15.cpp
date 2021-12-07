#include <iostream>
using namespace std;

int main()
{
    int h, m, s;
    cout << "nhap gio, phut, giay: \n";
    cin >> h >> m >> s;
    bool isTime = false;
    if (s < 60)
    {
        if (m < 60)
        {
            if (h < 24)
            {
                isTime = true;
            }
        }
    }

    if (isTime)
    {
        printf("gio, phut giay nhap vao hop le: %02d:%02d:%02d\n", h, m, s);
        s--;
        if (s == -1)
        {
            s = 59;
            m--;
            if (m == -1)
            {
                m = 59;
                h--;
                if (h == -1)
                {
                    h = 23;
                }
            }
        }
        printf("sau khi giam 1s: %02d:%02d:%02d\n", h, m, s);
    }
    else
    {
        cout << "khong hop le \n";
    }
    return 0;
}
