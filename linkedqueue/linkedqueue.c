/*
 * Implementation for Linked queue.
 */

#include "linkedqueue.h"

void init_queue(Queue* q){
	q->front = NULL;
	q->rear = NULL;
}

void enqueue(Queue* q, element e){
	Node* tmp = (Node*)malloc(sizeof(Node));

	if(tmp == NULL){
		fprintf(stderr, "enqueue: failed to allocate memory.\n");
		exit(1);
	}

	tmp->data = e;
	tmp->link = NULL;

	if(q->rear == NULL){
		q->front = tmp;
		q->rear = tmp;
	}
	else {
		q->rear->link = tmp;
		q->rear = tmp;
	}

	return;
}

element dequeue(Queue* q){
	if(is_empty(q)){
		fprintf(stderr, "dequeue: dequeued from an empty queue.\n");
		exit(1);
	}

	element tmp = q->front->data;
	Node* ptmp = q->front->link;
	free(q->front); // 메모리가 여유롭다면 생략 가능.
	q->front = ptmp; // NULL이면 알맞은 처리를 해주지 않는구나
	if(q->front == NULL){ q->rear = NULL; }

	return tmp;
}

element peek(Queue* q){
	return q->front->data;
}

int is_empty(Queue* q){
	return (q->front == NULL && q->rear == NULL)? 1 : 0;
}