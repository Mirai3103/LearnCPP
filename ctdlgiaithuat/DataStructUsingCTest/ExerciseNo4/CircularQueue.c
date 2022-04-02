#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
//define the circular queue structure
struct CircularQueue
{
    int front,rear;
    int size;
    int *queue;
};
// function prototypes
struct CircularQueue* createCircularQueue(int size);
void cqInsert(struct CircularQueue *q,int data);
int cqDelete(struct CircularQueue *q);
void cqDisplay(struct CircularQueue *q);
// main function
int main()
{
    struct CircularQueue *q = createCircularQueue(SIZE); // ⮚ Initialize the array of 10 elements and name it as queue
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
                cqInsert(q, data);
                break;
            case 2:// the choice= Dequeue so call the function qDelete()  
                data = cqDelete(q);
                if(data != -1)
                    printf("The deleted element is %d\n", data);
                break;
            case 3:// the choice= display so call the function qDisplay() 
                cqDisplay(q);
                break;
            case 4: // the choice= exit so exit from the program ⮚ end  
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
   
    return 0;
}
// function to create the circular queue
struct CircularQueue* createCircularQueue(int size)
{
    struct CircularQueue *q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->queue = (int*)malloc(sizeof(int)*size);
    q->size = size;
    q->front = q->rear = -1;
    return q;
}
// function to insert the element in the circular queue
void cqInsert(struct CircularQueue *q,int data)
{
    if(q->front == -1)
    {
        q->front = q->rear = 0;
        q->queue[q->rear] = data;
    }
    else if((q->rear+1)%q->size == q->front)
        printf("Queue is full\n");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->queue[q->rear] = data;
    }
}
// function to delete the element from the circular queue
int cqDelete(struct CircularQueue *q)
{
    if(q->front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int data = q->queue[q->front];
        if(q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front+1)%q->size;
        return data;
    }
}
// function to display the elements of the circular queue
void cqDisplay(struct CircularQueue *q)
{
    if(q->front == -1)
        printf("Queue is empty\n");
    else
    {
        int i = q->front;
        while(i != q->rear)
        {
            printf("%d ", q->queue[i]);
            i = (i+1)%q->size;
        }
        printf("%d\n", q->queue[i]);
    }
}