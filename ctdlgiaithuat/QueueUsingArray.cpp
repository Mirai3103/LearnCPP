#include <iostream>
#include <math.h>
using namespace std;

struct Queue
{
    int *arr;
    int front;
    int rear;
    int size;
};

Queue *createQueue(int size)
{
    Queue *queue = new Queue();
    queue->size = size;
    queue->arr = new int[size];
    queue->front = 0;
    queue->rear = 0;
    return queue;
}
