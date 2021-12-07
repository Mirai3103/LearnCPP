#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b;
tieptuc:
    cout << "nhap 2 so a va b: \n";
    cin >> a >> b;
    cout << "nhap phep toan (+ , - , * , /, % ): ";
    char pheptoan;
    fflush(stdin);
    cin >> pheptoan;
    switch (pheptoan)
    {
        case '+':
            printf("%d+%d=%d", a, b, a + b);
            break;
        case '-':
            printf("%d-%d=%d", a, b, a - b);
            break;
        case '*':
            printf("%d*%d=%d", a, b, a * b);
            break;
        case '/':
            if(b==0){
                printf("khong the chia cho 0");
                break;
            }
            printf("%d/%d=%d", a, b, a * 1.0 / b);
            break;
        case '%':

            cout << a << "%" << b << "=" << a % b;
            break;

        default:
            cout << "phep toan khong hop le!\n";
            break;
    }
    cout << "\nban co muon tiep tuc su dung(Y/N): ";
    char tieptuc;
    cin >> tieptuc;
    if (tolower(tieptuc) == 'y')
    {
        goto tieptuc;
    }
    else
    {
        cout << "tam biet";
    }
    return 0;
}
