#include "linkeddeque.h"

void init_deque(Deque* q){
	q->front = NULL;
	q->rear = NULL;
}

void add_front(Deque* q, element e){
	Node* tmp = (Node*)malloc(sizeof(Node));
	if(tmp == NULL){
		fprintf(stderr, "Memory allocation failed.\n");
		exit(1);
	}

	tmp->data = e;
	if(is_empty(q)){
		q->front = tmp;
		q->rear = tmp;
	} else {
		tmp->llink = NULL;
		tmp->rlink = q->front;
		q->front->llink = tmp;
		q->front = tmp;
	}
	return;
}

void add_rear(Deque* q, element e){
	Node *tmp = (Node*)malloc(sizeof(Node));
	if(tmp == NULL){
		fprintf(stderr, "Memory allocation failed.\n");
		exit(1);
	}

	tmp->data = e;
	if(is_empty(q)){
		q->front = tmp;
		q->rear = tmp;
	} else {
		tmp->llink = q->rear;
		tmp->rlink = NULL;
		q->rear->rlink = tmp;
		q->rear = tmp;
	}
	return;
}

element delete_front(Deque* q){
	if(is_empty(q)){
		fprintf(stderr, "delete_front: Deleted from an empty deque.");
		exit(2);
	}
	element tmp = q->front->data;
	Node* deleted = q->front;
	if(q->front == q->rear){
		q->front = NULL;
		q->rear = NULL;
	} else {
		q->front->rlink->llink = NULL;
		q->front = q->front->rlink;
	}
	free(deleted);
	return tmp;
}

element delete_rear(Deque* q){
	if(is_empty(q)){
		fprintf(stderr, "delete_rear: Deleted from an empty deque.");
		exit(2);
	}
	element tmp = q->rear->data;
	Node* deleted = q->rear;

	if(q->front == q->rear){
		q->front = NULL;
		q->rear = NULL;
	} else {
		q->rear->llink->rlink = NULL;
		q->rear = q->rear->llink;
	}
	free(deleted);
	return tmp;
}

element peek_front(Deque* q){
	if(is_empty(q)){
		fprintf(stderr, "peek_front: Peeked an empty deque.");
		exit(3);
	}
	return q->front->data;
}

element peek_rear(Deque* q){
	if(is_empty(q)){
		fprintf(stderr, "peek_rear: Peeked an empty deque.");
		exit(3);
	}
	return q->rear->data;
}

int is_empty(Deque* q){
	return (q->front == NULL && q->rear == NULL)? 1 : 0;
}