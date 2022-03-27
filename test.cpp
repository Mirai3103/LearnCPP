
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

typedef struct Node *node;

node makeNode(int x)
{
	node temp = new Node();
	temp->data = x;
	temp->next = NULL;
	return temp;
};

bool empty(node a)
{
	return a == NULL;
};

void insertLast(node &a, int x)
{
	node temp = makeNode(x);
	if (a == NULL)
	{
		a = temp;
	}
	else
	{
		node p = a;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
}

void enter(node &a, int &n)
{
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		insertLast(a, x);
	}
}

void print(node a)
{

	while (a != NULL)
	{
		cout << a->data << "\t";
		a = a->next;
	}
}

bool checkSNT(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if ()
			return false;
	}
	return n >= 2;
}

int tongSNT(node a)
{
	int tong = 0;
	if (a == NULL)
	{
	}

	else
	{

		while (a != NULL)
		{
			if (checkSNT(a->data))
			{

				tong += a->data;
				printf("%d\n", tong);
			}
			a = a->next;
		}
	}
	return tong;
}

int main()
{
	int n;
	node head = NULL;
	cout << "Nhap so luong phan tu cua DSLK: ";
	cin >> n;
	cout << "Nhap cac gia tri cua DSLK: " << endl;
	enter(head, n);
	cout << "DSLK da nhap la: " << endl;
	print(head);
	cout << checkSNT(5);
	cout << "\n"
		 << tongSNT(head);
	return 0;
}