#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next, *prev;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int count;
} LinkedList;

// function prototypes
void initialize(LinkedList *list);
void insertLast(LinkedList *list, int data);
void insertFirst(LinkedList *list, int data);
void insertMiddle(LinkedList *list, int data, int position);
void deleteData(LinkedList *list, int data);
void display(LinkedList list);
void showMenu();

// main function
int main()
{
    int choice, data;
    LinkedList list;
    initialize(&list);
    while (1)
    {
        showMenu();
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter any number: ");
            scanf("%d", &data);
            insertLast(&list, data);
            char more;
            do
            {
                printf("Enter more(y/n): ");
                fflush(stdin);
                scanf(" %c", &more);
                if (more == 'y')
                {
                    printf("Enter any number: ");
                    scanf("%d", &data);
                    insertLast(&list, data);
                }
            } while (more == 'y');

            break;
        case 2:
            printf("Enter the Data to be inserted at Beginning: ");
            scanf("%d", &data);
            insertFirst(&list, data);
            break;
        case 3:
            printf("Enter the Position to be Inserted: ");
            int position;
            scanf("%d", &position);
            printf("Enter the Data: ");
            scanf("%d", &data);
            insertMiddle(&list, data, position);
            break;
        case 4:
            printf("Enter the Data to be Deleted: ");
            scanf("%d", &data);
            deleteData(&list, data);
            break;
        case 5:
            printf("The Number of Nodes: %d\n", list.count);
            break;
        case 6:
            display(list);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}


// function definitions
void initialize(LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

void insertLast(LinkedList *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (list->count == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->count++;
}

void insertFirst(LinkedList *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (list->count == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->count++;
}


void insertMiddle(LinkedList *list, int data, int position)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    Node *temp = list->head;
    int i;
    for (i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    list->count++;
}

void deleteData(LinkedList *list, int data)
{
    Node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (temp == list->head)
            {
                list->head = temp->next;
                list->head->prev = NULL;
            }
            else if (temp == list->tail)
            {
                list->tail = temp->prev;
                list->tail->next = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            list->count--;
            break;
        }
        temp = temp->next;
    }
}

void display(LinkedList list)
{
    Node *temp = list.head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}