/*
 * Ngo Huu Hoang
 * 3121560032
 */
#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <conio.h>
// #include <Windows.h>
#include <unistd.h>
using namespace std;

struct Vehicle
{
    string name;
    int soDk;
};

struct Node
{
    Vehicle vehicle;
    Node *nextNode;
};

struct Queue
{
    Node *front;
    Node *rear;
    int size;
};
Queue *createQueue()
{
    Queue *q = new Queue();
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}
bool isEmpty(Queue *q)
{
    return q->front == NULL;
}
void enQueue(Queue *q, Vehicle vehicle)
{
    Node *node = new Node();
    node->vehicle = vehicle;
    node->nextNode = NULL;
    if (isEmpty(q))
    {
        q->front = q->rear = node;
    }
    else
    {
        q->rear->nextNode = node;
        q->rear = node;
    }
    q->size++;
}
Vehicle *deQueue(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty" << endl;
        return NULL;
    }
    else
    {

        q->size--;
        Node *temp = q->front;
        q->front = q->front->nextNode;
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        Vehicle *vehicle = new Vehicle();
        vehicle->name = temp->vehicle.name;
        vehicle->soDk = temp->vehicle.soDk;
        delete temp;
        return vehicle;
    }
}
void showQueue(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        Node *temp = q->front;
        while (temp != NULL)
        {
            cout << temp->vehicle.name << " " << temp->vehicle.soDk << endl;
            temp = temp->nextNode;
        }
    }
}
int main()
{

    srand(time(NULL));
    Queue *q = createQueue();
    int n;
    Vehicle vehicle;
    int count = 0;
    string list[3] = {"container", "tai", "khach"};
    bool stop = false;
    char c = '1';
    printf("press esc to stop\n");
    printf("\n");
    while (c != (char)27)
    {
        do
        {
            n = rand() % 5;
            for (int i = 0; i < n; i++)
            {
                vehicle.name = "xe " + list[rand() % 3];
                vehicle.soDk = count++;
                if (q->size == 20)
                {
                    break;
                }
                enQueue(q, vehicle);
                cout << "Di vao Loai xe: " << vehicle.name << " Ma so: " << vehicle.soDk << endl;
                sleep(1);
            }

            if (isEmpty(q) || q->size == 20)
            {
                showQueue(q);
                break;
            }
            Vehicle *a = deQueue(q);
            cout << "Di ra loai xe: " << a->name << " ma so: " << a->soDk << endl;
            sleep(1);
        } while (!kbhit());
        c = getchar();
    }

    return 0;
}
