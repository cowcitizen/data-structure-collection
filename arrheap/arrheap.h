/**
 * Implementation of max-heap using an array. WORK IN PROGRESS.
 */

#ifndef _ARRHEAP_H_
#define _ARRHEAP_H_

#ifndef MAX_HEAP_SIZE
#define MAX_HEAP_SIZE 128
#endif

typedef int element;

typedef struct max_heap{
	element* arr;
	int size;
} MaxHeap;

// Initialize the max-heap. (Allocate memory, Reset size to 0)
void init_max_heap(MaxHeap*);

// Free the memory space that the heap was using. Does NOT free the Heap pointer itself.
void del_max_heap(MaxHeap*);

// Insert a new element into a max-heap.
void insert(MaxHeap*, element);

// Remove the topmost element from a max-heap and return it.
element remove(MaxHeap*);

void print_max_heap(MaxHeap*);

#endif