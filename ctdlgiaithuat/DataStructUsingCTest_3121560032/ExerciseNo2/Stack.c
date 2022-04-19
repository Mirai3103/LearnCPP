#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
// define the stack structure
typedef struct 
{
    int top;
    int *stack;
}Stack;

// function prototypes
Stack* createStack(int size);
void push(Stack *s,int data);
int pop(Stack *s);
void display(Stack *s);



// main function
int main()
{
    Stack *s = createStack(SIZE); // ⮚ Initialize the array of 10 elements and name it as stack  
    int choice, data; // ⮚ Initialize other variables like top in the beginning of the program
    while(1)
    {
        //⮚ Provide the choice to the users for the different operations on stack
        printf("Enter the operation to be performed: 1) push 2) pop 3) display 4) exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1://the choice= push so call the function push()  
                printf("Enter the number to be Add: ");
                scanf("%d", &data);
                push(s, data);
                break;
            case 2:// the choice= pop so call the function pop()  
                data = pop(s);
                if(data != -1)
                    printf("The deleted element is %d\n", data);
                break;
            case 3:// the choice= display so call the function display() 
                display(s);
                break;
            case 4: // the choice= exit so exit from the program ⮚ end  
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


// function definition;
Stack* createStack(int size)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->stack = (int*)malloc(sizeof(int)*size);
    s->top = -1;
    return s;
}

void push(Stack *s, int data)
{
    if(s->top == SIZE-1)
    {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->stack[s->top] = data;
}
int pop(Stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    int data = s->stack[s->top];
    s->top--;
    return data;
}
void display(Stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for(int i = 0; i <= s->top; i++)
        printf("%d ", s->stack[i]);
    printf("\n");
}