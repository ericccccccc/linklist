#ifndef LINKLIST
#define LINKLIST

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	int data;
	struct Node *next;
} Node;

Node *CrtNewNode(int val);

void PopBegin(Node **node);

void PopEnd(Node **node);

void Delete(Node **node, int val);

void InsertBegin(Node **node, int val);

void InsertEnd(Node **node, int val);

void InsertAfter(Node **node, int specific_val,int val);

bool Find(Node **node, int val);

Node *Find2(Node **node, int val); // Find the val, if found return NULL, else return Last Node
Node *FindValNode(Node **node, int val);

void Travel(Node **node);

#endif
