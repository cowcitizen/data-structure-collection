/* Interactive testing program for linked deque. */

#include<stdio.h>
#include "linkeddeque.h"

int main(void){
	char cinput;
	int dinput;
	Deque* d = (Deque*)malloc(sizeof(Deque));
	init_deque(d);

	printf("`ef` or `er` to enqueue, `df` or `dr` to dequeue, `pf` or `pr` to peek, `q` to quit, `h` or `?` for more.\n");
	while(1){
		scanf(" %c", &cinput);
		switch(cinput){
			case 'h':
			case '?':
				printf("This is an interactive test program for double-ended queue.\n");
				printf("Enter characters to select menu. Substitute any integer for {n}.\n");
				printf("ef {n} - enqueue {n} to the front end.\n");
				printf("er {n} - enqueue {n} to the rear end.\n");
				printf("df - dequeue from the front end.\n");
				printf("dr - dequeue from the rear end.\n");
				printf("pf - peek at the front end.\n");
				printf("pr - peek at the rear end.\n");
				printf("q - quit out of the program.\n");
				printf("h or ? - display this help.\n");
				printf("\n2024, Written by Jaebum Kim\n");
				break;
			case 'e':
			case 'i': // i for `insert` is accepted as well
				scanf(" %c", &cinput);
				if(cinput == 'f'){
					scanf("%d", &dinput);
					add_front(d, dinput);
				} else if(cinput == 'r'){
					scanf("%d", &dinput);
					add_rear(d, dinput);
				} else {
					fprintf(stderr, "Unknown direction: %c\n", cinput);
				}
				break;
			case 'd':
				scanf(" %c", &cinput);
				if(cinput == 'f'){ printf("%d\n", delete_front(d)); }
				else if(cinput == 'r'){ printf("%d\n", delete_rear(d)); }
				else { fprintf(stderr, "Unknown direction: %c\n", cinput); }
				break;
			case 'p':
				scanf(" %c", &cinput);
				if(cinput == 'f'){ printf("%d\n", peek_front(d)); }
				else if(cinput == 'r'){ printf("%d\n", peek_rear(d)); }
				else { fprintf(stderr, "Unknown direction: %c\n", cinput); }
				break;
			case 'q':
				printf("Really quit? (y/n) ");
				scanf(" %c", &cinput);
				if(cinput != 'y' && cinput != 'Y'){
					printf("Excellent!!!\n");
					break;
				}
			case 'Q': // intentional. `Q` exits without prompting.
				return 0;
				break;
			default:
				fprintf(stderr, "Unknown option: %c\n", cinput);
		}
	}
}