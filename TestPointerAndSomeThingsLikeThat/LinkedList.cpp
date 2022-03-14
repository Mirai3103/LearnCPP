#include <iostream>

using namespace std;
struct Node
{
    int value;
    Node *next;
};
struct LinkedList
{
private:
    Node *lastNode;
    Node *firstNode;

public:
    LinkedList()
    {
        firstNode = NULL;
        lastNode = NULL;
    }
    bool add(int value)
    {
        if (firstNode == NULL)
        {
            firstNode = new Node();
            firstNode->value = value;
            firstNode->next = NULL;
            lastNode = firstNode;
            return true;
        }
        Node *temp = new Node();
        temp->value = value;
        temp->next = NULL;
        lastNode->next = temp;
        lastNode = temp;
        return true;
    }
    bool addFist(int valu)
    {
        if (firstNode == NULL)
        {
            firstNode = new Node();
            firstNode->value = valu;
            firstNode->next = NULL;
            lastNode = firstNode;
            return true;
        }
        Node *temp = new Node();
        temp->value = valu;
        temp->next = firstNode;
        firstNode = temp;
        return true;
    }
    bool deleteFirstValue(int valu)
    {
        Node *nextNode;
        nextNode = this->firstNode;
        while (nextNode != NULL)
        {
            if (nextNode->next != NULL)
            {
                if (nextNode->next->value == valu)
                {
                    Node *WillDelete = nextNode->next;
                    nextNode->next = nextNode->next->next;
                    delete WillDelete;
                    return true;
                }
            }
            nextNode = nextNode->next;
        }
        return false;
    }
    void deleteAllValue(int valu)
    {
        Node *nextNode;
        nextNode = this->firstNode;
        while (nextNode != NULL)
        {
            if (nextNode->next != NULL)
            {
                if (nextNode->next->value == valu)
                {
                    Node *WillDelete = nextNode->next;
                    nextNode->next = nextNode->next->next;
                    delete WillDelete;
                }
            }
            nextNode = nextNode->next;
        }
    }
    Node *getFirstNode()
    {
        return this->firstNode;
    }
};

int main()
{
    Node *nextNode;

    LinkedList list;
    list.add(2);
    list.add(1);
    list.add(3);
    list.add(4);
    list.add(3);
    list.add(6);
    list.deleteFirstValue(3);
    list.addFist(10);
    nextNode = list.getFirstNode();
    while (nextNode != NULL)
    {
        cout << nextNode->value;
        nextNode = nextNode->next;
    }
}