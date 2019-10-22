#include<stdint.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"heap.h"

Heap heap_new(int32_t data[], uint32_t len)
{
	assert(len>0 && len<HEAP_MAX_SIZE);
	Heap heap;
	for(uint32_t parent=len/2;parent>0;--parent)
	{
		_heapify_(data,len,parent);
	}
	heap.size=len;
	memcpy(heap.data,data,(len+1)*sizeof(int32_t));
	return heap;
}
void _swap_(int32_t *a, int32_t *b)
{
	int32_t *temp;
	temp=a;
	a=b;
	b=temp;
}
static void _heapify_(int32_t data[], uint32_t len,uint32_t parent)
{
	assert(len>0 && len<HEAP_MAX_SIZE && parent >0);
	uint32_t child=2*parent;
	while(child<=len)
	{
		if(child+1 <= len)
		{
			if(data[child+1]<data[child])
			{
				++child;
			}
		}	
        if(data[parent]>=data[child])
        {
        	break;
        }
        
        _swap_(&data[parent],&data[child]);
        parent=child;
        child=2*parent;
		
	}
}

static void test_heap(int32_t data[],uint32_t len)
{
	for(uint32_t idx=len;idx>1;--idx)
	{
		assert(data[idx]<=data[idx/2]);
	}
}



Heap* heap_sort(Heap *heap)
{
	assert(heap->size>0 && heap->size<HEAP_MAX_SIZE);
	for(uint32_t idx=heap->size;idx>0;--idx)
	{
		_swap_(&heap->data[1],&heap->data[idx]);
		_heapify_(heap->data,idx-1,1);

	}
	return heap;
}