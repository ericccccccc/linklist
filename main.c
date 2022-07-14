#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	Node *head = CrtNewNode(10);

	for(int i=0;i<5;i++)
	{
		InsertBegin(&head, i*i);
	}

	for(int i=0;i<5;i++)
	{
		InsertEnd(&head, i*i);
	}

	Delete(&head, 16);

	PopBegin(&head);
	PopEnd(&head);

	Travel(&head);

	return 0;
}