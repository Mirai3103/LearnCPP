#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *stack;
    int top;
    int size;
} Stack;

// function prototype

// stack
Stack *createStack(int size);
void push(Stack *stack, char c);
char pop(Stack *stack);
char peek(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);

// inFix to posFix
int isOperator(char c);
int getPriority(char c);
char *inFixToPosFix(char inFix[], int length);

// calculate posFix
int toInt(char c);
float calculate(char a, char b, char operato);
float evaluate(char *posFix, int length);

// main function
int main()
{
    char inFix[100];
    int length;
    char *posFix;
    float result;
    printf("Enter the Infix Expression: ");
    scanf("%s", inFix);
    length = strlen(inFix);
    posFix = inFixToPosFix(inFix, length);
    printf("The Postfix Expression is: %s\n", posFix);
    printf("Do you want to evaluate the Result of Postfix Expression?(Y/N): ");
    char ans;
    scanf(" %c", &ans);
    if (ans == 'Y' || ans == 'y')
    {
        result = evaluate(posFix, length);
        printf("Result: %f\n", result);
    }
    return 0;
}

// function definition
Stack *createStack(int size)
{
    Stack *rs = (Stack *)malloc(sizeof(Stack));
    rs->stack = (char *)malloc(sizeof(char) * size);
    rs->top = -1;
    rs->size = size;
    return rs;
}

int isFull(Stack *stack)
{
    return stack->top == stack->size - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top < 0;
}

void push(Stack *stack, char c)
{
    if (isFull(stack))
    {
        printf("Stack is full");
    }
    else
    {
        stack->stack[++(stack->top)] = c;
    }
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty");
        return '\0';
    }
    else
    {
        return stack->stack[stack->top--];
    }
}

char peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty");
        return '\0';
    }
    else
    {
        return stack->stack[stack->top];
    }
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

int getPriority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
    {
        return 2;
    }
    return 3;
}

char *inFixToPosFix(char inFix[], int length)
{

    Stack *operatorStack = createStack(length);
    char *posFix = (char *)malloc(sizeof(char) * length + 1);
    posFix[length] = '\0';
    int i = 0, j = 0;
    while (inFix[i] != '\0')
    {
        if (isOperator(inFix[i]))
        {
            if (isEmpty(operatorStack))
            {
                push(operatorStack, inFix[i++]);
            }
            else
            {
                if (getPriority(inFix[i]) <= getPriority(peek(operatorStack)))
                {
                    posFix[j++] = pop(operatorStack);
                }
                else
                {
                    push(operatorStack, inFix[i++]);
                }
            }
        }
        else
        {
            posFix[j++] = inFix[i++];
        }
    }
    while (!isEmpty(operatorStack))
    {
        posFix[j++] = pop(operatorStack);
    }
    return posFix;
}
int toInt(char c)
{
    return c - '0';
}
float calculate(float x, float y, char operato)
{

    switch (operato)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x * 1.0 / y;
    }
    return -1.0;
}
float evaluate(char *posFix, int length)
{
    float numberStack[length];
    int top = 0;
    int i = 0;
    while (posFix[i] != '\0')
    {
        if (isOperator(posFix[i]))
        {
            float b = numberStack[--top];
            float a = numberStack[--top];
            numberStack[top++] = calculate(a, b, posFix[i++]);
        }
        else
        {
            numberStack[top++] = toInt(posFix[i++]);
        }
    }
    return numberStack[0];
}