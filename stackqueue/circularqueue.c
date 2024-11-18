/**
 * Circular queue: Implementation using an array.
 */

#include<stdio.h>
#include<stdlib.h>
#include "circularqueue.h"

int main(void){}

void init_queue(Queue* q){
	q->front = 0;
	q->rear = 0;
}

void enqueue(Queue* q, int x){
	if(is_full(q)){
		fprintf(stderr, "Enqueued to a full queue.\n");
		exit(1);
	}
	q->rear += 1;
	q->rear %= MAX_QUEUE_SIZE;
	q->data[q->rear] = x;
	return;
}

element dequeue(Queue* q){
	if(is_empty(q)){
		fprintf(stderr, "Dequeued from an empty queue.\n");
		exit(1);
	}
	q->front += 1;
	q->front %= MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int is_full(Queue* q){
	return (q->rear+1) % MAX_QUEUE_SIZE == (q->front) % MAX_QUEUE_SIZE ? 1 : 0;
}

int is_empty(Queue* q){
	return q->rear == q->front ? 1 : 0;
}

element peek(Queue* q){
	return q->data[(q->front+1)%MAX_QUEUE_SIZE];
}
