#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_
#include<stdint.h>

#define HEAP_MAX_SIZE 32

typedef struct  _heap_ Heap;

struct _heap_
{
	uint32_t size;
	int32_t data[HEAP_MAX_SIZE];

};

Heap heap_new(int32_t data[], uint32_t len);
static void _heapify_(int32_t data[], uint32_t len,uint32_t parent);
Heap* heap_sort(Heap *heap);
uint32_t heap_size(Heap *heap);
Heap* heap_add(Heap *heap, int32_t key);
int32_t heap_get_max(Heap *heap);

void _swap_(int32_t *a, int32_t *b);
#endif

