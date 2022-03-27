#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>

using namespace std;

struct Car
{
    string name;
    int soDk;
};

struct Node
{
    Car car;
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
}
bool isEmpty(Queue *q)
{
    return q->front == NULL;
}
void enQueue(Queue *q, Car car)
{
    Node *node = new Node();
    node->car = car;
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
Car *deQueue(Queue *q)
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
        Car *car = new Car();
        car->name = temp->car.name;
        car->soDk = temp->car.soDk;
        delete temp;
        return car;
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
            cout << temp->car.name << " " << temp->car.soDk << endl;
            temp = temp->nextNode;
        }
    }
}
int main()
{
    srand(time(NULL));
    Queue *q = createQueue();
    int n;
    Car car;
    int count = 0;
    string list[3] = {"container", "tai", "khach"};
    bool stop = false;
    while (true)
    {

        n = rand() % 5;
        for (int i = 0; i < n; i++)
        {
            car.name = "Car " + list[rand() % 3];
            car.soDk = count++;
            if (q->size == 20)
            {
                break;
            }
            enQueue(q, car);
            cout << "Enqueue Loai xe: " << car.name << " Ma so: " << car.soDk << endl;
            _sleep(1000);
        }

        if (isEmpty(q) || q->size == 20)
        {
            showQueue(q);
            break;
        }
        Car *a = deQueue(q);
        cout << "Dequeue loai xe: " << a->name << " ma so: " << a->soDk << endl;
        _sleep(1000);
    }

    return 0;
}
