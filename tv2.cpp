#include <stdio.h>
#include <chrono>
#include <iostream>
#include <math.h>
using namespace std::chrono;
using namespace std;
void timso(int n){

    int max = 0;
    int temp = n;
    int count = 0;
    while (temp != 0)
    {
        max = max + temp % 10;
        temp = temp / 10;
        count++;
    }
    int cc;
    printf("n: %d \n", n);
    int x = (n-pow(10,count-1));
    for (int i = n; i > x; i--)
    {
        int s = 0;
        temp = i;
        while (temp != 0)
        {
            s = s + temp % 10;
            temp = temp / 10;
        }
        if (s > max)
        {
            max = s;
            cc = i;
        }
    }
    printf("ket qua: so %d co tong %d", cc, max);
}
int main()
{
    int max = 0;
    int cc;
    int arr[] ={7,55,574,2243,8978,22345,87878,8882884};
    for (int j = 0; j < 8; j++)
    {
        auto start = high_resolution_clock::now();
        // for (int i =arr[j]; i > 0; i--)
        // {
        //     int s = 0, temp = i;

        //     while (temp != 0)
        //     {
        //         s = s + temp % 10;
        //         temp = temp / 10;
        //     }
        //     if (s > max)
        //     {
        //         max = s;
        //         cc = i;
        //     }
        // }
          printf("gia thiet %d\n", arr[j] );
        timso(arr[j]);
        auto stop = high_resolution_clock::now();
      
        auto duration = duration_cast<microseconds>(stop - start);
        cout << endl
             << "thoi gian thuc hien:" << duration.count() << " microSeccond" << endl;
        cout << "=======================\n";
        /* code */
    }

    return 0;
}