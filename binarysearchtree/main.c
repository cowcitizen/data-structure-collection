/*
 * 이진 탐색 트리(Binary search tree)라는 걸 배웠다.
 * 삽입, 삭제, 탐색 같은 기능을 한번 만들어보자.
 */

#include<stdio.h>
#include "bstree.h"

int main(void){
	char cinput;
	int dinput;
	TreeNode* index;
	TreeNode* tree = NULL;

	// 아... 트리가 비어있을 때 처리를 어떻게 해야 할지 생각나지 않는다.......
	// 처음부터 다시 짜야 할지도 모르겠음. ㅋㅋㅋㅋ ㅋ   ㅋ  ㅋㅋ ㅋㅋ ㅋ  ㅋ ㅋㅋ
	// insert()의 반환형을 TreeNode* 로 한다면 어찌어찌 할 수는 있어보이는데... 근데 피곤함. 이따가 해야지~! ^^

	// 그러니까... 시마도 너무 대충대충 살아가는 건 좋지 못한 일이고.......
	// 그건 미츠미에게나 그렇겠지.

	printf("`f` to find, `i` to insert, `r` to remove, `p` to print, `q` to quit, `h` or `?` for more.\n");
	while(1){
		scanf(" %c", &cinput);
		switch(cinput){
			case '?':
			case 'h':
				printf("This is a binary search tree testing program.\n");
				printf("Enter a character to select menu.\n");
				printf("f - find if the specified number is in the tree.\n");
				printf("i - insert the specified number into a tree.\n");
				printf("r - remove the specified number from a tree.\n");
				printf("p - print all numbers in the tree.\n");
				printf("q - quit out of the program.\n");
				printf("h or ? - display this help.\n");
				printf("\n2024, Written by Jaebum Kim\n");
				break;
			case 'f':
				scanf("%d", &dinput);
				index = find(tree, dinput);
				if(index == NULL){
					printf("%d is not found.\n", dinput);
				} else {
					printf("%d is found on address %p.\n", dinput, index);
				}
				break;
			case 'i':
				scanf("%d", &dinput);
				if(tree == NULL){
					tree = tinsert(NULL, dinput);
				} else {
					tinsert(tree, dinput);
				}
				break;
			case 'r':
				scanf("%d", &dinput);
				tree = tremove(tree, dinput);
				break;
			case 'p':
				printall(tree);
				printf("\n");
				break;
			case 'q':
				printf("Really quit? (y/n) ");
				scanf(" %c", &cinput);
				if(cinput != 'y' && cinput != 'Y'){
					printf("Excellent!!!\n");
					break;
				}
			case 'Q':
				return 0; // quit out of the program...
				break;
			default:
				fprintf(stderr, "Unknown option: %c\n", cinput);
		}
	}
}