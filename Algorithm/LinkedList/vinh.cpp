#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    int data;
};

struct LinkedList
{
    Node *head;
    int size;
};

LinkedList *createList()
{
    LinkedList *list = new LinkedList();
    list->head = NULL;
    list->size = 0;
    return list;
}
void insertLast(LinkedList *list, int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (list->head == NULL)
    {
        list->head = temp;
    }
    else
    {
        Node *p = list->head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    list->size++;
}
LinkedList *createList(int *arr, int n) // tạo bằng 1 array
{
    LinkedList *list = createList();
    for (int i = 0; i < n; i++)
    {
        insertLast(list, arr[i]);
    }
    return list;
}
void chenTheoBai4(LinkedList *list, int x)
{

    if (list->head == NULL)
    {
        insertLast(list, x);
    }
    else
    {
        Node *p = list->head;
        if (x >= 0)
        {
            while (p->next != NULL && p->next->data < x && p->next->data >= 0)
            {
                p = p->next;
            }
        }
        else
        {
            while (p->next != NULL && p->next->data >= 0)
            {
                p = p->next;
            }
            while (p->next != NULL && p->next->data > x)
            {
                p = p->next;
            }
        }
        Node *temp = new Node();
        temp->data = x;
        temp->next = p->next;
        p->next = temp;
        list->size++;
    }
}
void print(LinkedList *list)
{
    Node *p = list->head;
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->next;
    }
}
void bai14(LinkedList *giaThiet, LinkedList *ketQuat)
{
    Node *p = giaThiet->head;
    while (p != NULL)
    {
        chenTheoBai4(ketQuat, p->data);
        p = p->next;
    }
}
int main()
{
    int arr[] = {2, -5, -23, 6, 12, -59, -45, 45};
    LinkedList *giaThiet = createList(arr, 8);
    LinkedList *ketQua = createList();
    bai14(giaThiet, ketQua);
    printf("Gia thiet: ");
    print(giaThiet);
    cout << endl;
    printf("Ket qua: ");
    print(ketQua);
    return 0;
}
