#ifndef _CIRCULARQUEUE_H_
#define _CIRCULARQUEUE_H_

#ifndef MAX_QUEUE_SIZE
#define MAX_QUEUE_SIZE 100 // 최대 수용 가능한 자료 수 == MAX_QUEUE_SIZE - 1이다.
#endif

typedef int element;

// front = 첫 번째 요소 하나 앞의 인덱스, rear = 마지막 요소의 인덱스.
// 기본적으로 한 칸을 비워두는데, count 변수 같은 걸 활용해서 빈칸 없이 구현하는 방법도. (어디 한번 해보세요)
// 그냥 front % QUEUE_SIZE를 사용하면 되겠구나... (오버플로하면?) (그때그때 mod하면 될 일 아닌가요?)
typedef struct queue{
	int front, rear; // 포인터를 사용할 수도 있을 듯....
	element data[MAX_QUEUE_SIZE];
} Queue;

void init_queue(Queue*);
void enqueue(Queue*, int);
element dequeue(Queue*);
int is_full(Queue*); // returns 1 if TRUE, 0 if FALSE.
int is_empty(Queue*);
element peek(Queue*);

#endif