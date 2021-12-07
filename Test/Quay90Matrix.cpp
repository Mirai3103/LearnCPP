#include <iostream>
using namespace std;

int main()
{          
    int n = 3, m =4;//0  1  2  3   
    int arr[n][m] = {{2, 3, 6, 4},//0
                     {3, 2, 1, 9},//1
                     {7, 8, 5, -1}};//2
    
    int quay90doquatrai[m][n];
    for (int j = m-1; j >=0; j--)
        for (int i = 0; i < n; ++i)
        {
            quay90doquatrai[m-j-1][i] = arr[i][j];
        }

    cout << "\nquay 90 do qua ben trai: " << endl;
   for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
         cout << " " << quay90doquatrai[i][j];
         if (j == n - 1)
            cout << endl;
      }
          return 0;
}
