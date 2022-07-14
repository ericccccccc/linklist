#include "linklist.h"


void PopBegin(Node **node)
{
	Node *curr = *node;
	*node = curr->next;
	free(curr);
}

void PopEnd(Node **node)
{
	Node *curr = *node,
		  *prev = NULL;
	while(curr->next) 
	{
		prev = curr;
		curr = curr->next;
	}

	prev->next = NULL;
	free(curr);
}

void Delete(Node **node, int val)
{
	Node *prev = NULL, 
		 *curr = *node;
	if(curr->data == val)
	{
		PopBegin(node);
		return;
	}

	while(curr)
	{
		if(curr->data == val)
		{
			prev->next = curr->next;

			free(curr);

			return;
		}

		prev = curr;
		curr = curr->next;
	}

}

Node* CrtNewNode(int val)
{
	Node *newNode = malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

void InsertBegin(Node **node, int val)
{
	if(!Find(node, val))
	{
		Node *curr = *node;
		Node *newNode = CrtNewNode(val);
		newNode->next = curr;
		*node = newNode;	
	}
}

void InsertEnd(Node **node, int val)
{
	Node *curr = Find2(node, val);
	if(curr)
	{
		Node *newNode = CrtNewNode(val);
		curr->next = newNode;	
	}
}

void InsertAfter(Node **node, int specific_val, int val)
{
	if(Find(node, val)) return;
	Node *specific_node = FindValNode(node, specific_val);
	if(specific_node) return;

	Node *newNode = CrtNewNode(val);

	newNode->next = specific_node->next;
	specific_node->next = newNode;
}


bool Find(Node **node, int val)
{
	Node *curr = *node;

	while(curr)
	{
		if(curr->data == val) return true;
		curr = curr->next;
	}

	return false;
}


/*
	if found return NULL, else return Last Node
*/ 
Node *Find2(Node **node, int val)
{
	Node *curr = *node,
		 *prev = NULL;

	while(curr)
	{
		if(curr->data == val) return NULL;
		
		prev = curr;
		curr = curr->next;
	}

	return prev;

}

/*
	Found: return Val Node
	Not Found: return NULL
*/ 
Node *FindValNode(Node **node, int val)
{
	Node *curr = *node;

	while(curr)
	{
		if(curr->data == val) return curr;
		curr = curr->next;
	}

	return NULL;

}

void Travel(Node **node)
{
	printf("[Travel]\n");

	Node *curr = *node;

	while(curr)
	{
		printf(" %d -->", curr->data);
		curr = curr->next;
	}

	printf(" NULL\n");
}