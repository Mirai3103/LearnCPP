#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct
{
    int coff;
    int exp;
} Element;

typedef struct
{
    Element arr[100];
    int size;
} Poly;

void input(Poly *p);
void display(Poly *p);
void add(Poly *p1, Poly *p2, Poly *result);

int main()
{
    Poly p1, p2, result;
    printf("Enter the first polynomial::\n");
    input(&p1);
    printf("First polynomial is ::\n");
    display(&p1);
    printf("Enter the second polynomial::\n");
    input(&p2);
    printf("Second polynomial is ::\n");
    display(&p2);
    add(&p1, &p2, &result);
    printf("Addition of the two polynomials::");
    display(&result);
    return 0;
}

void input(Poly *p)
{
    p->size = 0;
    char ch;
    do
    {
        printf("Enter the coefficient :");
        scanf("%d", &(p->arr[p->size].coff));
        printf("Enter the power :");
        scanf("%d", &(p->arr[p->size].exp));
        p->size++;
        printf("\nContinue??? (Y/N) :");
        fflush(stdin);
        scanf(" %c", &ch);
    } while (tolower(ch) == 'y');
}
void display(Poly *p)
{
    for (int i = 0; i < p->size; i++)
    {
        if (p->arr[i].exp == 1)
            printf("%dx", p->arr[i].coff);
        else if (p->arr[i].exp == 0)
            printf("%d", p->arr[i].coff);
        else
            printf("%dx^%d", p->arr[i].coff, p->arr[i].exp);

            
        if (i == p->size - 1)
            printf("\n");
        else
            printf(" + ");
    }
}
void add(Poly *p1, Poly *p2, Poly *result)
{
    int i = 0, j = 0, k = 0;
    result->size = 0;
    while (i < p1->size && j < p2->size)
    {
        if (p1->arr[i].exp > p2->arr[j].exp)
        {
            result->arr[k++] = p1->arr[i++];
            result->size++;
        }
        else if (p1->arr[i].exp == p2->arr[j].exp)
        {
            result->arr[k].coff = p1->arr[i].coff + p2->arr[j].coff;
            result->arr[k].exp = p2->arr[j].exp;
            result->size++;
            j++;
            i++;
            k++;
        }
        else
        {
            result->arr[k++] = p2->arr[j++];
            result->size++;
        }
    }
    while (i < p1->size)
    {
        result->arr[k++] = p1->arr[i++];
        result->size++;
    }
    while (j < p2->size)
    {
        result->arr[k++] = p2->arr[j++];
        result->size++;
    }
}