#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
    int *arr;
    int size;
    int capacity;
} Heap;


// function prototypes
void init(Heap *h, int capacity);
void insert(Heap *h, int item);
void deleteRoot(Heap *h);
void printHeap(Heap *h);
void heapify(Heap *h, int i);
void input(Heap *h);
void swap(int *a, int *b);


// main function
int main()
{

    Heap h;
    input(&h);
    printf("Array representation of heap:\n");
    printHeap(&h);
    printf("Enter item to be inserted into heap: ");
    int item =-1;
    while(item ==-1)
    {
        scanf("%d", &item);
    }
    insert(&h, item);
    printf("Array representation of heap:\n");
    printHeap(&h);
    printf("After deletion of root\n");
    deleteRoot(&h);
    printHeap(&h);
    return 0;
}

// function definitions
void init(Heap *h, int capacity)
{
    h->arr = (int *)malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(Heap *h, int item)
{
    if (h->size == h->capacity)
        return;
    h->arr[h->size] = item;
    int i = h->size;
    h->size = h->size + 1;
    if(h->size==1) return;
     
    while (i != 0 && h->arr[i] > h->arr[(i - 1) / 2])
    {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void printHeap(Heap *h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%d  ", h->arr[i]);
    }
    printf("\n");
}
void heapify(Heap *h, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max;
    if (left >= h->size)
        return;
    if (right >= h->size)
        max = left;
    else
    {
        if (h->arr[left] > h->arr[right])
            max = left;
        else
            max = right;
    }
    if(h->arr[i] >= h->arr[max]){
        return;
    }
    else{
        swap(&h->arr[i] , &h->arr[max]);
        heapify(h, max);
    }
}
void deleteRoot(Heap *h)
{
    swap(&h->arr[0], &h->arr[h->size - 1]);
    h->size--;
    heapify(h, 0);
}
void input(Heap *h){
    h->size =0;
    h->capacity=100;
    h->arr = (int*)malloc(sizeof(int)*100);
    
    printf("Enter elements of heap (press 's' and enter to stop):\n");
    int item;
    while(scanf("%d",&item)==1){
        insert(h,item);
    }
    char temp = getchar();
}