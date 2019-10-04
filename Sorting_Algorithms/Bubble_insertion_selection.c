#include<stdint.h>

void _swap_(int32_t *a, int32_t *b)
{
	int32_t *temp;
	temp=&a;
	&a=&b;
	&b=temp;
}
void bubble_sort(int32_t list[], uint32_t size)
{
	uint32_t pass, index;
	for(pass=0;pass<size-1;++pass)
	{
		for(index=size-1;index>pass;--index)
		{
			if(list[index]<list[index-1])
			{
				_swap_(&list[index],&list[index-1]);
			}
		}
	}
}

void selection_sort(int32_t list[], uint32_t size)
{
	uint32_t pass, index, min_pos;
	for(pass=0;pass<n-1;++pass)
	{
		min_pos=pass;
		for(index=pass+1;index<size;++index)
		{
			if(list[index]<list[min_pos])
			{
				min_pos=index;
			}
		}
		_swap_(&list[pass],&list[min_pos]);
	}
}

void insertion_sort(int32_t list[], uint32_t size)
{
	int32_t pass,index,key;
	for(pass=1;pass<size;++pass)
	{
		key=list[pass];
		index=pass-1;
		while(index > 0 && list[index] >key)
		{
			list[index+1]=list[index];
			--index;
		}
		list[index+1]=key;
	}
}
