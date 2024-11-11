/*
 * Linked queue: Queue implemented using a singly linked list.
*/

#ifndef _LINKEDQUEUE_H // In case someone decides to include this twice....
#define _LINKEDQUEUE_H

#include<stdio.h>
#include<stdlib.h>

typedef int element; // change if needed

typedef struct linknode{
	element data;
	struct linknode* link;
} Node;

typedef struct linkqueue{
	Node* front;
	Node* rear;
} Queue;

void init_queue(Queue*);
void enqueue(Queue*, element);
element dequeue(Queue*	);
element peek(Queue*);
int is_empty(Queue*); // return 1 if empty, 0 otherwise

#endif