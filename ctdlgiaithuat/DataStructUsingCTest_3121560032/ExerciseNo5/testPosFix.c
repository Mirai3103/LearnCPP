#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getMucDoUuTien(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

void toPosFix2(char expresion[], char posFix[100])
{
    char stack[10];
    int top = 0;
    int k = 0;
    for (int i = 0; expresion[i] != '\0'; i++)
    {
        if (expresion[i] == '+' || expresion[i] == '-' || expresion[i] == '*' || expresion[i] == '/')
        {
            if (top == 0)
            {
                stack[top++] = expresion[i];
            }
            else
            {
                char c = stack[top - 1];
                if (getMucDoUuTien(c) < getMucDoUuTien(expresion[i]))
                {
                    stack[top++] = expresion[i];
                }
                else
                {
                    top--;
                    posFix[k++] = stack[top];

                    stack[top++] = expresion[i];
                }
            }
        }
        else
        {
            posFix[k++] = expresion[i];
        }
    }
    while (top != 0)
    {
        top--;
        posFix[k++] = stack[top];
        printf("%s\n", stack);
    }
}
int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    return 0;
}
int getPreOfOperator(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    return 3;
}
char posFix[100];
void toPosFix(char infix[])
{
    char stack[20];
    int i = 0, j = 0, top = 0;

    while (infix[i] != '\0')
    {
        if (isOperator(infix[i]))
        {
            if (top == 0)
            {
                stack[top++] = infix[i++];
            }
            else
            {
                if (getPreOfOperator(stack[top - 1]) < getPreOfOperator(infix[i]))
                {
                    stack[top++] = infix[i++];
                }
                else
                {
                    posFix[j++] = stack[--top];
                }
            }
        }
        else
        {
            posFix[j++] = infix[i++];
        }
    }
    while (top != 0)
    {
        posFix[j++] = stack[--top];
    }
}

int main()
{
    char expresion[] = "2a+b-c*2z/9-2";
    toPosFix(expresion);
    printf("%s", posFix);
    return 0;
}
