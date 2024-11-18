/* Testing program for circular queue. */

#include<stdio.h>
#include "circularqueue.h"

int main(void){
	Queue circularqueue;
	Queue* q = &circularqueue;
	init_queue(q);
	printf("`e` to enqueue, `d` to dequeue, `p` to peek, `q` to quit, `?` or `h` for help.\n");

	while(1){
		char selection;
		int data;
		printf("> ");
		scanf(" %c", &selection);
		switch(selection){
			case '?':
			case 'h':
				printf("This is a queue testing program.\n");
				printf("Enter `e` followed by a number to enqueue.\n");
				printf("Enter `d` to dequeue and `p` to peek. It will be printed to stdout.\n");
				printf("Enter `q y` or `Q` to exit the program.\n");
				break;
			case 'q':
				printf("Really quit? (y) ");
				scanf(" %c", &selection);
				if(selection != 'y' && selection != 'Y'){
					printf("Excellent!!!\n");
					break;
				}
			case 'Q':
				exit(0);
				break;
			case 'e':
				scanf(" %d", &data);
				enqueue(q, data);
				break;
			case 'd':
				data = dequeue(q);
				printf("%d\n", data);
				break;
			case 'p':
				data = peek(q);
				printf("%d\n", data);
				break;
			default:
				printf("Unknown command: %c\n", selection);
				break;
		}

	}
}