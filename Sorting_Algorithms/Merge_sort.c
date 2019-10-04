#include <stdint.h>

void merge_sort(int32_t list[], uint32_t low, uint32_t high)
{
	uint32_t mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(list,low,mid);
		merge_sort(list,mid+1,high);
		_merge_(list,low,mid,high);
	}
}

static void _merge_(int32_t list[], uint32_t low, uint32_t mid, uint32_t high)
{
	uint32_t f_index,s_index,t_index,idx;
	int32_t temp[size];
	f_index=t_index=low;
	s_index=mid+1;
	while(f_index <= mid && s_index <= high)
	{
		if(list[f_index] <= list[s_index])
		{
			temp[t_index++] = list[f_index++];
		}
		else
		{
			temp[t_index++]= list[s_index++];
		}
	}
	if(f_index > mid)
	{
		for(idx=s_index;idx<=high;++idx)
		{
			temp[t_index++]=list[idx];
		}
	}
	else
	{
		for(idx=f_index;idx<=mid;++idx)
		{
			temp[t_index++]=list[idx];
		}
	}
	/* Copy the temporary list into 
		the original list(array) */
	for(idx=low;idx<=high;++idx) 
	{
		list[idx++]=temp[idx];
	}			
}