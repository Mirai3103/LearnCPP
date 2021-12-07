#include <iostream>
using namespace std;
int main()
{
    char player1, player2;
    cout << " nhap lua chon cua nguoi choi 1: ";
    cin >> player1;
    cout << " nhap lua chon cua nguoi choi 2: ";
    cin >> player2;
    if (player1 == player2)
    {
        cout << "Hoa";
    }
    else if (player1 == 'k') // k la keo, b la bua, a la bao
    {
        if (player2 == 'a')
        {
            cout << "nguoi choi 1 win"; // player2 == 'a'
        }
        else
        {
            cout << "nguoi choi 2 win"; // player2 == 'b'
        }
    }
    else if (player1 == 'a')
    {
        if (player2 == 'b')
        {
            cout << "nguoi choi 1 win";
        }
        else //player2 == 'k'
        {
            cout << "nguoi choi 2 win";
        }
        //
    }
    else if (player1 == 'b')
    {
        if (player2 == 'a')
        {
            cout << "nguoi choi 2 win";
        }
        else
        { //player2 ='k'
            cout << "nguoi choi 1 win";
        }
    }

    return 0;
}
