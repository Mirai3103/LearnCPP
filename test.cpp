#include <iostream>

using namespace std;
struct Node
{
	int value;
	Node *next;
};
struct LinkedList
{

	Node *lastNode;
	Node *firstNode;
};
void add(LinkedList *list, float value)
{
	if (list->firstNode == NULL)
	{
		list->firstNode = new Node();
		list->firstNode->value = value;
		list->firstNode->next = NULL;
		list->lastNode = list->firstNode;
		return;
	}
	Node *temp = new Node();
	temp->value = value;
	temp->next = NULL;
	list->lastNode->next = temp;
	list->lastNode = temp;
}
void addFirst(LinkedList *list, float value)
{
	if (list->firstNode == NULL)
	{
		list->firstNode = new Node();
		list->firstNode->value = value;
		list->firstNode->next = NULL;
		list->lastNode = list->firstNode;
		return;
	}
	Node *temp = new Node();
	temp->value = value;
	temp->next = list->firstNode;
	list->firstNode = temp;
}
int main()
{
	LinkedList *list = new LinkedList();
	add(list, 1);
	add(list, 2);
	add(list, 3);
	add(list, 4);
	add(list, 5);
	add(list, 6);
	add(list, 7);
	add(list, 8);
	float x = 4.6;
	Node *nextNode = list->firstNode;
	float average = 0;
	int length = 0;
	while (nextNode != NULL)
	{
		average += nextNode->value;
		nextNode = nextNode->next;
		length++;
	}
	average = average / length;
	nextNode = list->firstNode;
	float min = abs(nextNode->value - average);
	Node *nearestNode = nextNode;
	while (nextNode != NULL)
	{
		if (abs(nextNode->value - average) < min)
		{
			min = abs(nextNode->value - average);
			nearestNode = nextNode;
		}
		nextNode = nextNode->next;
	}
	return 0;
}
