#include <stdio.h>
#include <windows.h>
void printToCoordinates(int y,int x,  const char *format, ...)
{
    va_list args;
    va_start(args, format);
    printf("\033[%d;%dH", x, y);
    vprintf(format, args);
    va_end(args);
    fflush(stdout);
}
void CreateCoordinates(int x = 40, int y = 20){
    system("cls");
    int Ox= x/2;
    int Oy = y/2;
    printToCoordinates(Ox,1,"^");
    for (int i = 2; i <= y; i++)
    {
        if(i == Oy){
            for (int j = 1; j <= x; j = j+2)
            {
                if(j == Ox){
                    printf("+");
                    continue;
                }
                printToCoordinates(j,i,"--");
            }
            printf(">");
        }else{
             printToCoordinates(Ox,i,"|");
        }
    }
    
}
void xuatdiem(int x, int y){
    CreateCoordinates();
    x = x + 10;
    y = 10-y;
    printToCoordinates(2*x,y,"*");
    x = 4;
    y = 2;
    x = x + 10;
    y = 10-y;
    printToCoordinates(2*x,y,"a");
    
}
int main()
{
    CreateCoordinates();
    xuatdiem(5,0);
    // xuatdiem(4,2);

    printToCoordinates(1,21,".");
    return 0;
}
