#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
//define the queue structure
typedef struct
{
    int front,rear;
    int size;
    int *queue;
}Queue;

// function prototypes
Queue* createQueue(int size);
void qInsert(Queue *q,int data);
int qDelete(Queue *q);
void qDisplay(Queue *q);


// main function
int main()
{
    Queue *q = createQueue(SIZE); // ⮚ Initialize the array of 10 elements and name it as queue
    int choice, data; // ⮚ Initialize other variables like rear and front in the beginning of the program
    while(1)
    {
        //⮚ Provide the choice to the users for the different operations on queue
        printf("Enter the operation to be performed: 1)Enqueue 2)Dequeue 3)Display 4)Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1://the choice= Enqueue so call the function qInsert()  
                printf("Enter the number to be Add: ");
                scanf("%d", &data);
                qInsert(q, data);
                break;
            case 2:// the choice= Dequeue so call the function qDelete()  
                data = qDelete(q);
                if(data != -1)
                    printf("The deleted element is %d\n", data);
                break;
            case 3:// the choice= display so call the function qDisplay() 
                qDisplay(q);
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
Queue* createQueue(int size)
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->queue = (int*)malloc(sizeof(int)*size);
    q->rear = -1;
    q->front = 0;
    q->size = size;
    return q;
}

void qInsert(Queue *q,int data)
{
    if(q->rear == q->size-1)
    {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->queue[q->rear] = data;
}
int qDelete(Queue *q)
{
    
    if(q->rear == q->front+1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->queue[q->front];
    q->front++;
    return data;
}

void qDisplay(Queue *q)
{
    if(q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d ",q->queue[i]);
    }
    printf("\n");
}