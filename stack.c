#include<stdint.h>
#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "stack.h"


stack stack_new(uint32_t size)
{
	size=((size>0&&size<32)?size:MAX_DEPTH);
	stack s={size,-1,{0}};
	return s;
}
uint32_t stack_full(const stack *stk)
{
	assert(stk!=NULL);
	return(stk->top+1==stk->size);
}
uint32_t stack_empty(const stack *stk)
{
	assert(stk!=NULL);
	return(stk->top==-1);	
}
stack* stack_push(stack *stk, _STACK_CONTENT_TYPE_ ele, stack_result *res)
{
	assert(stk!=NULL);
	if(stk->top+1 < stk->size)
	{
		stk->data[++stk->top]=ele;
		res->data=ele;
		res->status=STACK_OK;
	}
	else
	{
		res->status=STACK_FULL;
	}
	assert((res->status==STACK_OK)||(stk->top+1==stk->size));
	return stk;
}
stack* stack_pop(stack *stk, stack_result *res)
{
	assert(stk!=NULL);
	if(stk->top > -1)
	{
		
		res->data=stk->data[stk->top];
		--stk->top;
		res->status=STACK_OK;
	}
	else
	{
		res->status=STACK_EMPTY;
	}
	assert((res->status==STACK_OK)||(stk->top==-1));
	return stk;
}
stack* stack_peek(stack *stk, stack_result *res)
{
	assert(stk!=NULL);
	if(stk->top > -1)
	{
		
		res->data=stk->data[stk->top];
		
		res->status=STACK_OK;
	}
	else
	{
		res->status=STACK_EMPTY;
	}
	assert((res->status==STACK_OK)||(stk->top==-1));
	return stk;
}
