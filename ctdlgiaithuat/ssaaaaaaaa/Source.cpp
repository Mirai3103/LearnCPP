#include "SingleLinkedListImplement.h"

int main()
{
	Node *first;
	int a[] = {3, 5, 7, 10, 15};
	create(a, 5, &first);
	Display(first);
	printf("\n%d", add(first));
	printf("\n%d", max(first));
	return 0;
}