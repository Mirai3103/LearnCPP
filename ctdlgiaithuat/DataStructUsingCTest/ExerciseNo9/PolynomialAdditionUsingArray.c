
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// function prototypes
void input(int *a, int *n);
void addPolynomial(int *A, int *B, int *result, int n1, int n2, int *k);
void display(int *A, int n);

// main function
int main()
{
    int A[100] = {}, B[100]={}, result[100]={}, n1, n2,k;
    input(A, &n1);
    printf("First polynomial is ::\n");
    display(A, n1);
    input(B, &n2);
    printf("\nSecond polynomial is ::\n");
    display(B, n2);
    addPolynomial(A, B, result, n1, n2,&k);
    printf("\nAddition of the two polynomials::");
    display(result, k);
    return 0;
}

void input(int *a, int *n)
{
    *n = 0;
    int i, temp;
    char ch;
    printf("\nEnter the first polynomial::");
    do
    {
        printf("\nEnter the coefficient :");
        scanf("%d", &temp);
        printf("\nEnter the power :");
        scanf("%d", &i);
        a[i] = temp;
        if (i > *n)
            *n = i;

        printf("\nContinue??? (Y/N) :");
        fflush(stdin);
        scanf(" %c", &ch);

    } while (tolower(ch) == 'y');
}
void display(int *A, int n)
{
    int i;
    for (i = n; i >= 0; i--)
    {
        if (A[i] != 0)
        {
            if(i==n)
                printf("%dx^%d", A[i], i);
            else if(i==0)
                printf("+%d", A[i]);
            else
                printf("+%dx^%d", A[i], i);
        }
    }
}
void addPolynomial(int *A, int *B, int *result, int n1, int n2, int *k){

    int i=0, j=0, m =0;
    while (i <=n1 && j <= n2)
    {
        result[m++] = A[i++] + B[j++];
    }
    while (i <= n1)
    {
        result[m++] = A[i];
        i++;
    }
    while (j <= n2)
    {
        result[m++] = B[j];
        j++;
    }
    k = --m;
    printf("%d", k);;
}