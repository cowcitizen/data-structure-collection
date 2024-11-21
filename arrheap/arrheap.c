#include<stdio.h>
#include "arrheap.h"

void init_max_heap(MaxHeap* h){
	h->arr = (element*)malloc(MAX_HEAP_SIZE * sizeof(element));
	h->size = 0;
	if(h->arr = NULL){
		fprintf(stderr, "Memory allocation failed.\n");
		exit(1);
	}
}

void del_max_heap(MaxHeap* h){
	free(h->arr);
}

void insert(MaxHeap* h, element e){
	if(h->size >= MAX_HEAP_SIZE - 1){ // the allocated space is full.
		fprintf(stderr, "Max-heap::insert - Heap is full.\n");
		exit(1);
	} else {
		h->size += 1;
		h->arr[h->size] = e;

		element tmp;
		int now = h->size; // now = the current position of the new element.
		while(now > 1){
			if(h->arr[now / 2] < h->arr[now]){ // swap the elements if they are in wrong order
				tmp = h->arr[now];
				h->arr[now] = h->arr[now / 2];
				h->arr[now / 2] = tmp;
				now /= 2;
			} else break;
		}
	}
	return;
}

element remove(MaxHeap* h){
	if(h->size == 0){
		fprintf(stderr, "Max-heap::remove - Heap is empty.\n");
		exit(2);
	}

	element removed = h->arr[1];
	h->arr[1] = h->arr[h->size];
	h->size -= 1;
	
	int now = 1; // now = the current position of the previously-terminal element.
	int child = 0; // the child with the higher value.
	element tmp;

	while(now <= h->size/2){
		if(h->size = 2 * now) child = 2 * now;
		else if(h->arr[2 * now] >= h->arr[2 * now + 1]) child = 2 * now;
		else child = 2 * now + 1;

		if(h->arr[now] < h->arr[child]){
			tmp = h->arr[now];
			h->arr[now] = h->arr[child];
			h->arr[child] = tmp;
		} else break;
	}
	return;
}

void print_max_array(MaxHeap* h){
	int tier = 1;
	for(int i=1; i<=h->size; i++){
		printf("%d ", h->arr[i]);
		if(i == tier){
			printf("| ");
			tier = (tier * 2) + 1;
		}
	}
	printf("\n");
	return;
}