#include"stack.h"
#include<assert.h>
#include<stdio.h>
void test_empty_stack()
{
	stack s = stack_new(5);
	stack *stk = &s;
	assert(stack_full(stk)==0);
	assert(stack_empty(stk)==1);
}
void print_stack(stack *stk)
{
	for(int i=0; i<stk->size;i++)
	{
		printf("%d\t",stk->data[i] );
	}
}
void test_stack()
{
	
	stack s = stack_new(10);
	stack *stk = &s;
	stack_result res;

	stk=stack_push(stk,10,&res);
	print_stack(stk);
	stk=stack_peek(stk,&res);
	assert(res.status==STACK_OK && res.data==10);
	stk=stack_push(stk,20,&res);
	print_stack(stk);
	stk=stack_peek(stk,&res);
	stk=stack_pop(stk,&res);
	stk=stack_pop(stk,&res);
	assert(stack_empty(stk)==1);
}
	
int main()
{
	test_empty_stack();

	test_stack();

	printf("Execution done\n");
	
	return 0;
}