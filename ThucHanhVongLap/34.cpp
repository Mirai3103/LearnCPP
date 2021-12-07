#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int dem = 0;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 50; j++)
        {
            for (int k = 0; k <= 20; k++)
            {
                int tongtien = i * 100 + j * 200 + k * 500;
                if (tongtien == 10000)
                {
                    dem++;
                    printf("\nPhuong an %3d: %3d to 100, %2d to 200, %2d to 500", dem, i, j, k);
                }
            }
        }
    }

    return 0;
}
