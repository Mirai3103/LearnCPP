#include <stdio.h>

int main()
{

    int i, h, p, s;

    printf("Nhap gio: ");

    scanf("%d", &h);

    printf("Nhap phut: ");

    scanf("%d", &p);

    printf("Nhap giay: ");

    scanf("%d", &s);

    if ((h >= 0 && h <= 23) && (p >= 0 && p <= 59) && (s >= 0 && s <= 59))
    {

        printf("%d gio %d phut %d giay hop le", h, p, s);

        if (s == 59)
        {

            if (p == 59)
            {

                if (h == 23)

                    printf("\nGio sau do 1 giay la 00:00:00");

                else

                    printf("\nGio sau do 1 giay la %d:%d:%d", h + 1, p, s);
            }
            else

                printf("\nGio sau do 1 giay la %d:%d:%d", h, p + 1, s);
        }
        else

            printf("\nGio sau do 1 giay la %d:%d:%d", h, p, s + 1);
    }
    else

        printf("%d gio %d phut %d giay khong hop le", h, p, s);
}