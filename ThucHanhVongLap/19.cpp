#include <stdio.h>
void inbangcuuchuong(){
    for (int i = 1; i <= 10; i++) // in hang
    {
        for (int j = 2; j <= 9; j++)// in cot
        {
            printf("%2d x %2d =%2d    ", j,i,i*j);
        }
        printf("\n");
    }
}
int main()
{
    inbangcuuchuong();

    return 0;
}
