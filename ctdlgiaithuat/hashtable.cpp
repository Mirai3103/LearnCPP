#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *nextNode;
    Node()
    {
        this->data = -1;
        nextNode = nullptr;
    }
    Node(int value)
    {
        this->data = value;
        nextNode = nullptr;
    }
};

class HashTable
{
    int (*hash)(int);
    Node **table;
    HashTable(int size, int (*hashFunction)(int))
    {
        table = new Node *[size];
        this->hash = hashFunction;
    }
    void add(int value)
    {

        int key = hash(value);
        if (this->table[key]->nextNode == nullptr)
        {
            this->table[key]->data = value;
        }
        else
        {
            Node *node = new Node(value);
            Node *current = this->table[key];
            while (current->nextNode != nullptr)
            {
                current = current->nextNode;
            }
            current->nextNode = node;
        }
    }
    int search(int value)
    {
        int key = hash(value);
        if (this->table[key]->nextNode == nullptr)
        {
            if (this->table[key]->data == value)
            {
                return 1;
            }
        }
        else
        {
            Node *node = new Node(value);
            Node *current = this->table[key];
            while (current->nextNode != nullptr)
            {
                current = current->nextNode;
            }
            current->nextNode = node;
        }
    }
};

main(int argc, char const *argv[])
{

    return 0;
}
