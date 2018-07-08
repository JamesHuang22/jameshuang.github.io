#include <stdio.h>
#include <stdlib.h>

#ifndef trav_stack_datastructure_h
#define trav_stack_datastructure_h

/* A structure to represent a stack */

/* Use the dynamically allocated array to implment a stack */

typedef struct node
{
	char* name;
	struct Node* next;
}Node;

typedef struct Trav_stack
{
	int size;
	Node* head;
	Node* cursor;
}Trav_stack;



#endif 
