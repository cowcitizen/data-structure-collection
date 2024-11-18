/*
 * Linked deque: Double-ended queue implemented using a doubly linked list.
 *
 * Some implementations for doubly linked lists seem to use the head node instead of two pointers;
 * I decided to use two pointers because it does the job without problem.
 * 
 * `insert` and `delete` seems like the more common names for `enqueue` and `dequeue`...
 * I might change the name someday.
*/

#ifndef _LINKEDDEQUE_H
#define _LINKEDDEQUE_H

#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct dequenode{
	element data;
	struct dequenode* llink;
	struct dequenode* rlink;
} Node;

typedef struct deque{
	Node* front, * rear;
} Deque;

void init_deque(Deque*);

void add_front(Deque*, element);
void add_rear(Deque*, element);

element delete_front(Deque*);
element delete_rear(Deque*);

element peek_front(Deque*);
element peek_rear(Deque*);

int is_empty(Deque*);

#endif